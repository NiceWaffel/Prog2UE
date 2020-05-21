#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include <unistd.h>

#include "Renderer.h"
#include "Library.h"

#define BUFFER_SIZE 64

void input_loop(Library *lib, Credentials *creds) {
    Renderer::scr_clear();
    Renderer::scr_error("Press any key to quit!");

    return;

    // TODO

    while(1) {
        int c = Renderer::get_input();

        switch (c) {
            case 'f': // find book
                break;
            case 'a': // add book when logged in as admin
                break;
            case 'q':
                return;
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
    Renderer::scr_print("Username: ", 0, 0, 10);
    Renderer::scr_render();

    char string_buffer[BUFFER_SIZE];
    int current_pos = 0;

    // Init string_buffer to zero, so string ends at our last character
    memset(string_buffer, 0x0, BUFFER_SIZE);

    while(1) {
        int c = Renderer::get_input();
        if(c == 10) {
            if(current_mode == 0) { // Username
                std::string uname(string_buffer);
                creds->username = uname;

                Renderer::scr_print("Password: ", 1, 0, 10);
                Renderer::scr_render();

                // Reset buffers
                current_pos = 0;
                memset(string_buffer, 0x0, BUFFER_SIZE);

                // Change mode to password input
                current_mode = 1;
            }
            else if(current_mode == 1) { // Password
                std::string pass(string_buffer);
                creds->password = pass;

                // Check credentials and return success accordingly
                if(lib->check_creds(*creds))
                    return 1;
                else
                    return 0;
            }
            else {
                // Illegal state for current_mode
                return 0;
            }
        }
        else if(c > 31 && c < 126 && current_pos < BUFFER_SIZE) {
            string_buffer[current_pos] = c;
            current_pos++;

            if(current_mode == 0) {
                Renderer::scr_print(string_buffer, 0, 10, BUFFER_SIZE);
                Renderer::scr_render();
            }
            else if(current_mode == 1) {
                std::string stars(current_pos, '*');
                Renderer::scr_print(stars, 1, 10, BUFFER_SIZE);
                Renderer::scr_render();
            }
        }
    }
}

int main() {
    std::srand(std::time(NULL));

    int r = Renderer::init_renderer();
    if(r != 0) {
    	std::cerr << "Failed to initialize ncurses renderer!" << std::endl;
    	return 1;
    }
    
    Library *lib = new Library();

    int success;
    Credentials creds;
    do {
        success = login_screen(lib, &creds);
    } while(!success);
    input_loop(lib, &creds);

    delete lib;
    Renderer::cleanup_renderer();
}