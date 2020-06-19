#include <iostream>
#include <thread>
#include <mutex>
#include <string>

#include <cstdlib>

#include <curses.h>

#define MAX_ANIMATIONS 5

std::mutex mutex;
bool quit = false;
std::thread* threads[MAX_ANIMATIONS];

void animation(std::string text, int row) {
	int maxwidth = 20;
	int cur_x = 0;
	while(!quit) {
		for(size_t x = 0; x < maxwidth - text.length(); x++) {
			mutex.lock();
			for(size_t j = 0; j < x; j++) {
				mvprintw(row, cur_x++, "_");
			}
			mvprintw(row, cur_x, "%s", text.c_str());
			cur_x += text.length();
			for(size_t j = x + text.length() + 1; j < maxwidth; j++) {
				mvprintw(row, cur_x++, "_");
			}
			refresh();
			cur_x = 0;
			mutex.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
	}
}

void input_loop() {
	int row = 0;
	while(!quit) {
		int c = getch();

		switch(c) {
			case 'a': // Add another animation thread
				if(row < MAX_ANIMATIONS)
					threads[row] = new std::thread(animation, "TEXT", row++);
				break;
			case 'q':
				quit = true;
				break;
			default:
				break;
		}
	}

	return;

	for(int i = 0; i < row; i++) {
		threads[i]->join();
	}
	for(int i = 0; i < row; i++) {
		delete threads[i];
	}
}

int main() {
	initscr();
	cbreak(); // disable line buffering
	noecho(); // disable echo
	curs_set(0); // hide cursor

	std::thread input_thread(input_loop);
	input_thread.join();

	endwin();

	return 0;
}