#include "Renderer.h"
#include "Library.h"

#include <csignal>

#include <unistd.h>

#define TABLE_POS_TYPE 3
#define TABLE_POS_TITLE 18
#define TABLE_POS_YEAR 53
#define TABLE_POS_LENTTO 63

// Defined globally so quit() function can easily access it
static Library *lib;

void quit() {
	if(lib != nullptr)
		delete lib;
	Renderer::cleanup_renderer();
	exit(0);
}

void draw_listview(int selected_index, int &cur_offset, std::vector<Lendable> items) {
	Renderer::scr_clear();
	
    // Print table headings
    Renderer::scr_print("Type", 1, TABLE_POS_TYPE, 4);
    Renderer::scr_print("Title", 1, TABLE_POS_TITLE, 5);
    Renderer::scr_print("Year", 1, TABLE_POS_YEAR, 4);
    Renderer::scr_print("Lent to", 1, TABLE_POS_LENTTO, 7);

	int list_height = Renderer::get_rows() - 10;
	if(list_height < 0)
		return;
	if(list_height > items.size())
		list_height = items.size();
	
	if(selected_index <= cur_offset && selected_index > 0)
		cur_offset--;
	else if(selected_index >= cur_offset + list_height && selected_index <= items.size() - 1)
		cur_offset++;
		
	// print all visible items
	for(int i = cur_offset; i < cur_offset + list_height; i++) {
		int row = i - cur_offset + 3; // 3 lines of space above list for table heading
		Renderer::scr_print(items[i].get_attribute("type"), row, TABLE_POS_TYPE,
				TABLE_POS_TITLE - TABLE_POS_TYPE - 2);
		Renderer::scr_print(items[i].get_attribute("title"), row, TABLE_POS_TITLE,
				TABLE_POS_YEAR - TABLE_POS_TITLE - 2);
		Renderer::scr_print(items[i].get_attribute("year"), row, TABLE_POS_YEAR,
				TABLE_POS_LENTTO - TABLE_POS_YEAR - 2);
		
		if(items[i].get_attribute("lentto") != "unknown") {
			int lentto_id = stoi(items[i].get_attribute("lentto"));
			Renderer::scr_print(lib->get_customer(lentto_id).get_username(), row, TABLE_POS_LENTTO, 32);
		}
		else
			Renderer::scr_print("unknown", row, TABLE_POS_LENTTO, 32);
	}

	// Print selection identifier
	Renderer::scr_print(">", selected_index - cur_offset + 3, 1, 1);

	// Print login name
	Renderer::scr_print("Logged in as: ", Renderer::get_rows() - 2, TABLE_POS_TYPE, 14);
	Renderer::scr_print(lib->get_user().get_username(), Renderer::get_rows() - 2,
				TABLE_POS_TYPE + 14, 32);

	// Print keybindings
	std::string binds = "Keybinds: f - find item";
	switch(lib->get_user().get_permission_level()) {
		case 0: // guest
			binds += "  |  s - sign up";
			break;
		case 1: // customer
			// If selected item is already lent to customer, give back hotkey is printed
			// Else lend hotkey is printed
			if(items[selected_index].get_attribute("lentto") == std::to_string(lib->get_user().get_id()))
				binds += "  |  ENTER - give back";
			else
				binds += "  |  ENTER - lend";
			break;
		case 2: // admin
			// Not implemented: binds += "  |  a - add item";
			break;
		default:
			// TODO throw exception and fix customer file
			break;
	}
	binds += "  |  q - quit";
	Renderer::scr_print(binds, Renderer::get_rows() - 1, TABLE_POS_TYPE, binds.length());

	// Render the screen buffer
	Renderer::scr_render();
}


// Handles the login process
void login_screen() {
	Library::Credentials creds = {"", ""};

	do {
		int current_mode = 0;
		std::string buffer = "";
		
		Renderer::scr_clear();
		Renderer::scr_print("Username: ", 0, 0, 10);
		Renderer::scr_render();
		
		while(current_mode != 2) {
			int ch = Renderer::get_input();
			switch(ch) {
				case 27: // Escape
					quit();
					break;
				case 10: // Enter
					if(current_mode == 0) { // username input complete
						creds.username = buffer;
						buffer.clear();
						current_mode = 1;

						Renderer::scr_print("Password: ", 1, 0, 10);
					}
					else { // password input complete
						creds.password = buffer;
						buffer.clear();
						current_mode = 2;
					}
					break;
				case 8:
				case 263: // Backspace
					if(!buffer.empty()) {
						buffer.pop_back();
						if(current_mode == 0)
							Renderer::scr_print(" ", 0, buffer.length() + 10, 1);
						else
							Renderer::scr_print(" ", 1, buffer.length() + 10, 1);
					}
					break;
				default: // Other keys
					if(ch > 31 && ch < 127) {
						buffer.push_back(ch);
					}
					break;
			}
			if(current_mode == 0) {
				Renderer::scr_print(buffer, 0, 10, buffer.length());
				Renderer::scr_render();
				Renderer::set_cursor_pos(0, buffer.length() + 10);
			}
			else {
				std::string stars(buffer.length(), '*');
				Renderer::scr_print(stars, 1, 10, buffer.length());
				Renderer::scr_render();
				Renderer::set_cursor_pos(1, buffer.length() + 10);
			}
		}
	} while(!lib->login(creds));
}

std::string find_mode() {
	std::string buffer = "";
	Renderer::scr_print("Find: ", Renderer::get_rows() - 4, TABLE_POS_TYPE, 6);
	while(1) {
		Renderer::scr_print(buffer, Renderer::get_rows() - 4, TABLE_POS_TYPE + 6, buffer.length());
		Renderer::scr_render();
		
		int ch = Renderer::get_input();
		switch(ch) {
			case 27: // Escape
				return "";
			case 10: // Enter
				return buffer;
			default: // Ignore other keys
				if(ch > 31 && ch < 127)
					buffer.push_back(ch);
				break;
		}
	}
}

void sign_up_mode() {
	// TODO
}

void add_item_mode() {
	// TODO
}

/* The main input loop. Calls other functions for specific actions */
void input_loop() {
	std::vector<Lendable> shown_items;
	int selected_index = 0;
	int list_offset = 0;
	std::string search_term = "";

	while(1) {
		shown_items = lib->search(search_term);
		std::string lentto_id = shown_items[selected_index].get_attribute("lentto");
		draw_listview(selected_index, list_offset, shown_items);
		
		int ch = Renderer::get_input();
		switch(ch) {
			case 27: // Escape
			case 'q':
				quit();
				break;
			case 'f':
				search_term = find_mode();
				break;
			case 'a':
				if(lib->get_user().get_permission_level() == 2) // is admin
					add_item_mode();
				break;
			case 's':
				if(lib->get_user().get_permission_level() == 0) // is guest
					sign_up_mode();
				break;
			case KEY_UP:
				if(selected_index > 0)
					selected_index--;
				break;
			case KEY_DOWN:
				if(selected_index < shown_items.size() - 1)
					selected_index++;
				break;
			case 10: // Enter
				// check if lent to logged in user
				if(lentto_id == std::to_string(lib->get_user().get_id()))
					lib->give_back(shown_items[selected_index].get_id());
				else if(lib->get_user().get_permission_level() >= 1)
					lib->lend(shown_items[selected_index].get_id());
				break;
			default: // Ignore other keys
				break;
		}
	}
}

void resize_handler(int new_rows, int new_cols) {
	// TODO
}

void signal_handler(int signum) {
	quit();
}

int main(int argc, char **argv) {

	Renderer::init_renderer();
	Renderer::register_resize_handler(resize_handler);

	// Register handler for SIGTERM (Ctrl+c) and SIGINT
	signal(SIGTERM, signal_handler);
	signal(SIGINT, signal_handler);

	lib = new Library("./inventory.txt", "./customers.txt");

	login_screen();
	input_loop();

	quit();

	// Will never be reached
	return 0;
}
