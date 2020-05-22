#include "Renderer.h"

Renderer::Renderer() {}

Renderer::~Renderer() {}

/* Updates the terminal size measurements when the terminal is resized */
void Renderer::upd_tersz() {
	struct winsize w;
	// Gets the terminal dimensions and stores the in w
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	ter_rows = w.ws_row;
	ter_cols = w.ws_col;
}

/* Handles the SIGWINCH signal, which occurs on a terminal resize */
void Renderer::handle_winch(int sig) {
	// Update the stored terminal dimensions
	upd_tersz();

	// Resize the screen buffer
	screen_buffer = (char *) realloc(screen_buffer, ter_rows * ter_cols * sizeof(char));

	// Call the callback functions for terminal resize events
	for(auto func : resize_handlers) {
		func(ter_rows, ter_cols);
	}
}

/* Initializes the Renderer instance and ncurses */
int Renderer::init_renderer() {
	initscr();				// Initialze ncurses
	cbreak();				// Disables line buffering
	noecho();				// Disable input echoing
	keypad(stdscr, TRUE);	// Enable arrow keys
	clear();				// Clear the screen

	upd_tersz();

	screen_buffer = (char *) calloc(ter_rows * ter_cols, sizeof(char));
	if(screen_buffer == nullptr)
		return 1;

	signal(SIGWINCH, handle_winch);	// Register the signal handler

	return 0;
}

void Renderer::cleanup_renderer() {
	free(screen_buffer);
	endwin();
}

int Renderer::cursor_hide(bool hidden) {
	return curs_set(!hidden);
}

/* Registers a callback function for resize events.
 * These functions need two integers as parameters for rows
 * and columns respectivly */
void Renderer::register_resize_handler(void (*handler)(int, int)) {
	resize_handlers.push_back(handler);
}

/* Wrapper for ncurses input function */
int Renderer::get_input() {
	return getch();
}

/* Renders the screen buffer to the terminal screen */
void Renderer::scr_render() {
	clear();
	for(int i = 0; i < ter_rows * ter_cols; i++) {
		if(screen_buffer[i] > 31)
			mvaddch(i / ter_cols, i % ter_cols, screen_buffer[i]);
	}
	refresh();
}

/* Clears the screen buffer */
void Renderer::scr_clear() {
	memset(screen_buffer, 0x0, ter_rows * ter_cols);
}

/* Prints a messagebox that can be closed with any key */
void Renderer::scr_error(std::string message) {
	char *buffer_backup = screen_buffer;
	screen_buffer = (char *) malloc(ter_rows * ter_cols * sizeof(char));
	memcpy(screen_buffer, buffer_backup, ter_rows * ter_cols);
	int x = ter_cols / 2 - 20;
	int y = ter_rows / 2 - 4;

	scr_print("+---------------------------------------+\r"
		      "|                                       |\r"
		      "|                                       |\r"
		      "|                                       |\r"
		      "|                                       |\r"
		      "|                                       |\r"
		      "|               <   OK   >              |\r"
		      "+---------------------------------------+", y, x, 40);
	scr_print(message, y + 1, x + 1, 38);
	scr_render();
	getchar();
	free(screen_buffer);
	screen_buffer = buffer_backup;
	scr_render();
}

/* Prints the string given by the argument at position x, y.
 * Wordwrap is not implemented for now.
 * maxlen determines the point, at which should be wrapped
 * Tabs, some other control characters and unicode characters are ignored. */
void Renderer::scr_print(std::string text, int row, int col, int maxlen) {
	int c_col = col;
	int c_row = row;
	int i;
	char c;

	for(i = 0; i < text.length(); i++) {
		c = text[i];
		if(c > 126) // Probably unicode character (or DEL)
			continue;
			
		switch(c) {
			case '\r': // carriage return
				c_col = col;
				break;
			case '\n': // line feed
				c_row++;
				break;
			default:
				if(c > 31) {// Ignore control chars
					buffer(c_row, c_col, c);
					c_col++;
					if(c_col > col + maxlen) {
						c_col = col;
						c_row++;
					}
				}
				break;
		}
	}
}

/* Write a character to the screen buffer */
void Renderer::buffer(int row, int col, char c) {
	// Check whether in drawing area
	if(row < 0 || col < 0 || row >= ter_rows || col >= ter_cols)
		return;
	
	// Write char to screen buffer
	screen_buffer[col + row * ter_cols] = c;
}

/* Getters for the terminal dimesions */
int Renderer::get_rows() {return ter_rows;}
int Renderer::get_cols() {return ter_cols;}
