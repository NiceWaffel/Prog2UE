#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>

#include <unistd.h>

#include "Renderer.h"
#include "Library.h"

#define BUFFER_SIZE 64

#define TABLE_POS_TYPE 3
#define TABLE_POS_TITLE 18
#define TABLE_POS_YEAR 53
#define TABLE_POS_LENTTO 63

void redraw_listview(Library *lib, int selected_index, std::vector<Lendable> items) {
    // Clear screen
    Renderer::scr_clear();

    // Print table headings
    Renderer::scr_print("Type", 1, TABLE_POS_TYPE, 4);
    Renderer::scr_print("Title", 1, TABLE_POS_TITLE, 5);
    Renderer::scr_print("Year", 1, TABLE_POS_YEAR, 4);
    Renderer::scr_print("Lent to", 1, TABLE_POS_LENTTO, 7);

    // Print info for all items in the list or all items that fit on screen
    for(int i = 0; i < items.size() && i < Renderer::get_rows() - 5; i++) {
        switch(items[i].get_type()) {
            case LENDABLE_TYPE_BOOK:
                Renderer::scr_print("Book", i + 3, TABLE_POS_TYPE, 12);
                break;
            case LENDABLE_TYPE_AUDIOBOOK:
                Renderer::scr_print("Audiobook", i + 3, TABLE_POS_TYPE, 12);
                break;
            case LENDABLE_TYPE_VIDEOGAME:
                Renderer::scr_print("Videogame", i + 3, TABLE_POS_TYPE, 12);
                break;
            default:
                Renderer::scr_print("Invalid Type", i + 3, TABLE_POS_TYPE, 12);
                break;
        }

        Renderer::scr_print(items[i].get_title(), i + 3, TABLE_POS_TITLE, TABLE_POS_YEAR - TABLE_POS_TITLE - 2);
        Renderer::scr_print(std::to_string(items[i].get_year()).substr(0, 4), i + 3, TABLE_POS_YEAR, 4);

        if(items[i].lent_to_id() == 0)
            Renderer::scr_print("Nobody", i + 3, TABLE_POS_LENTTO, 20);
        else
            Renderer::scr_print(lib->get_customer_name(items[i].lent_to_id()), i + 3, TABLE_POS_LENTTO, 20);
    }

    // Print seletion identifier
    Renderer::scr_print(">", selected_index + 3, 1, 1);

    // Print login name
    Renderer::scr_print("Logged in as: ", Renderer::get_rows() - 2, TABLE_POS_TYPE, 14);
    Renderer::scr_print(lib->get_login_name(), Renderer::get_rows() - 2, TABLE_POS_TYPE + 14, 50);

    // Print keybindings
    std::string binds("Keybinds: f - find item");
    
    if(lib->get_login_name().compare("guest") == 0)
        binds += "  |  s - sign up";
    else if(lib->get_login_name().compare("admin") == 0)
    	binds += "  |  a - add item";
    binds += "  |  q - quit";
    
    Renderer::scr_print(binds, Renderer::get_rows() - 1, TABLE_POS_TYPE, Renderer::get_cols());
}

void sign_up_screen(Library *lib) {

}

void search_mode() {
	
}

/* Main input loop for the list view */
void input_loop(Library *lib) {
    int selected_index = 0;
    std::vector<Lendable> shown_items;

    shown_items = lib->search("");
    
    Renderer::scr_clear();

    while(1) {
        // Draw screen
        redraw_listview(lib, selected_index, shown_items);
        Renderer::scr_render();

        // Wait for input
        int c = Renderer::get_input();
        switch (c) {
            case 'f': // find book
            	search_mode();
                break;
            case 'a': // add book when logged in as admin
                // TODO
                break;
            case 's':
                if(lib->get_login_name().compare("guest") == 0) { // If we are logged in as guest
                    sign_up_screen(lib);
                }
                break;
            case 10: // Enter
                if(shown_items[selected_index].lent_to_id() == lib->get_my_id()) { // If already mine, give back
                    lib->give_back(shown_items[selected_index].get_id());
                }
                else {
                    lib->lend(shown_items[selected_index].get_id());
                }
                break;
            case 'q':
                return;
            case KEY_UP:
                if(selected_index > 0)
                    selected_index--;
                break;
            case KEY_DOWN:
                if(selected_index < shown_items.size() - 1)
                    selected_index++;
                break;
            default:
                break;
        }
    }
}

/* Returns 1 when credentials are valid for the given Library
 * Input credentials will be stored in creds, even if invalid */
int login_screen(Library *lib, Credentials *creds) {
    int current_mode = 0;

    Renderer::scr_clear();
    Renderer::scr_render();

    char string_buffer[BUFFER_SIZE];
    int current_pos = 0;

    // Init string_buffer to zero, so string ends at our last character
    memset(string_buffer, 0x0, BUFFER_SIZE);

    Renderer::scr_clear();
    Renderer::scr_print("Username: ", 0, 0, 10);
    Renderer::scr_render();

    while(1) {
        int c = Renderer::get_input();
        if(c == 10) {
            if(current_mode == 0) { // Username
                std::string uname(string_buffer);
                creds->username = uname;

                // Reset buffers
                current_pos = 0;
                memset(string_buffer, 0x0, BUFFER_SIZE);

                // Change mode to password input
                current_mode = 1;
                
            	Renderer::scr_print("Password: ", 1, 0, 10);
            }
            else if(current_mode == 1) { // Password
                std::string pass(string_buffer);
                creds->password = pass;

                // Check credentials and return success accordingly
                if(lib->login(*creds))
                    return 1;
                else
                    return 0;
            }
            else {
                // Illegal state for current_mode
                return 0;
            }
        }
        else if(c == 8 || c == 263) { // Backspace
        	if(current_pos > 0)
            	current_pos--;
            string_buffer[current_pos] = 0x0;
            Renderer::scr_print(" ", current_mode, 10 + current_pos, 1); // Very evil! (using current_mode as row argument)
        }
        else if(c > 32 && c < 126 && current_pos < BUFFER_SIZE) {
            string_buffer[current_pos] = c;
            current_pos++;
        }

        if(current_mode == 0) {
            Renderer::scr_print(string_buffer, 0, 10, BUFFER_SIZE);
        }
        else if(current_mode == 1) {
            std::string stars(current_pos, '*');
            Renderer::scr_print(stars, 1, 10, BUFFER_SIZE);
        }
        Renderer::scr_render();
    }
}

int main() {
    std::srand(std::time(NULL));
    
    int r = Renderer::init_renderer();
    if(r != 0) {
    	std::cerr << "Failed to initialize ncurses renderer!" << std::endl;
    	return 1;
    }
    Renderer::cursor_hide(true);

    Library *lib = new Library(".");
	
    int success;
    Credentials creds;
    do {
        success = login_screen(lib, &creds);
    } while(!success);
    input_loop(lib);

    delete lib;
    Renderer::cleanup_renderer();
}
