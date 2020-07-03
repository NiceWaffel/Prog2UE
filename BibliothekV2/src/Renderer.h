#pragma once

#include <ncurses.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

class Renderer {
	private:
		Renderer();
		~Renderer();
		
		static char *screen_buffer;
		static int ter_rows, ter_cols;
		static std::vector<void (*)(int, int)> resize_handlers;

		static void upd_tersz();
		static void handle_winch(int sig);

		static void buffer(int row, int col, char c);
	public:
		struct Position {
			int row, col;
		};
	
		static int init_renderer();
		static void cleanup_renderer();

		static int set_cursor_visible(bool visible);
		static void set_cursor_pos(int row, int col);
		static Position get_cursor_pos();

		static void register_resize_handler(void (*handler)(int, int));
		
		static int get_input();
		
		static void scr_render();
		static void scr_clear();
		static void scr_error(std::string message);
		static void scr_print(std::string text, int row, int col, int maxlen);

		static int get_rows();
		static int get_cols();
};
