#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include <unistd.h>

#include "Renderer.h"
#include "Library.h"

#define MODE_LOGIN_USERNAME 0
#define MODE_LOGIN_PASSWD 1
#define MODE_LIST 2

#define BUFFER_SIZE 64

static int current_mode = MODE_LOGIN_USERNAME;

static std::string *username = new std::string("");

static Library *lib;

void input_loop() {
    char *string_buffer = (char *) calloc(BUFFER_SIZE, sizeof(char));
    int current_len = 0;
    Renderer::scr_print("Username: ", 0, 0, 20);
    Renderer::scr_render();
    while(1) {
        int c = Renderer::get_input();
        if(current_mode == MODE_LOGIN_USERNAME) {
            if(c == 10) {
                std::string s(string_buffer);
                *username += s;
                current_mode = MODE_LOGIN_PASSWD;
                Renderer::scr_print(*username, 4, 0, 40);
                Renderer::scr_print("Password: ", 1, 0, 20);
                Renderer::scr_render();
                current_len = 0;
                memset(string_buffer, 0x0, BUFFER_SIZE);
            } else if(c > 31 && c < 126) {
                if(current_len < BUFFER_SIZE) {
                    string_buffer[current_len] = c;
                    current_len++;
                    Renderer::scr_print(string_buffer, 0, 10, BUFFER_SIZE);
                    Renderer::scr_render();
                }
            }
        } else if(current_mode == MODE_LOGIN_PASSWD) {
            if(c == 10) {
                // TODO if Library::check_creds(); then
                if(0) {
                    current_mode = MODE_LIST;
                } else {
                    /* Invalid credentials; reset to MODE_LOGIN_USERNAME */
                    current_mode = MODE_LOGIN_USERNAME;
                    username->clear();
                    current_len = 0;
                    memset(string_buffer, 0x0, BUFFER_SIZE);
                    Renderer::scr_clear();
                    Renderer::scr_print("Username: ", 0, 0, 20);
                    Renderer::scr_render();
                }
            } else if(c > 31 && c < 126) {
                if(current_len < BUFFER_SIZE) {
                    string_buffer[current_len] = c;
                    current_len++;
                    Renderer::scr_print(string_buffer, 1, 10, BUFFER_SIZE);
                    Renderer::scr_render();
                }
            }
        } else if(current_mode == MODE_LIST) {
            switch (c) {
                case 'f': // find book
                    break;
                case 'a': // add book when logged in as admin
                    break;
                default:
                    break;
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
    
    lib = new Library();

    input_loop();

    Renderer::cleanup_renderer();
}