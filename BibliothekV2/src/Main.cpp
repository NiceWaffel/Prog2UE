#include "Renderer.h"
#include "Library.h"

#include <csignal>

/* Die globale Instanz des Library Objekts
 * Global definiert damit der Zugriff durch den
 * resize_handler und signal_handler möglich ist */
static Library *lib;

/*
 * Räumt auf und beendet das Programm
 */
void quit(Library *lib) {
	if(lib != nullptr)
		lib->cleanup();
	Renderer::cleanup_renderer();
	exit(0);
}

/*
 * Gibt bei einer erfolgreichen Anmeldung true zurück
 * Wenn der User die Anmeldung abbricht
 */
void show_login_screen(Library *lib) {
	Credentials *creds;
	bool shift_mod; // Brauch ich das?

	do {
		while(1) {
			int ch = Renderer::get_input();
			switch(ch) {
				case 27: // Escape
					quit(lib);
					break;
				case 10: // Enter
					// TODO
					break;
				case 8: // Backspace
					// TODO
					break;
				case 127: // Delete
					// TODO
					break;
				default: // Alle anderen Tasten
					// TODO
					break;
			}
		}
	} while(!check_creds(creds));
}

void input_loop(Library *lib) {

	while(1) {
		int ch = Renderer::get_input();
		// TODO
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

	signal(SIGTERM, signal_handler);

	
	lib = new Library();
	lib->load_inventory("inventory.dat");
	lib->load_customers("customers.dat");

	show_login_screen(lib);
	

	/* Wie nie erreicht */
	return 0;
}
