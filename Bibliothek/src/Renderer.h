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

static char *screen_buffer;
static int ter_rows, ter_cols;
static std::vector<void (*)(int, int)> resize_handlers;

class Renderer {
	private:
		Renderer();
		~Renderer();

		static void upd_tersz();
		static void handle_winch(int sig);

		static void buffer(int row, int col, char c);
	public:
		static int init_renderer();
		static void cleanup_renderer();

		static void register_resize_handler(void (*handler)(int, int));
		
		static int get_input();
		
		static void scr_render();
		static void scr_clear();
		static void scr_error(std::string message);
		static void scr_print(std::string text, int row, int col, int maxlen);

		static int get_rows();
		static int get_cols();
};
