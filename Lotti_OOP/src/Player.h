#pragma once

#include <iostream>

#include "Game.h"

#define FIGURE_COUNT 4

class Game;

class Player {
	private:
		int id;
		int m_figures[FIGURE_COUNT];
		bool lost;
		Game *game;

		void win();
		void move_fig(int fig, int rel_pos);
	public:
		Player(int id, Game *game);
		~Player() = default;
		void move();
		void check_death();
		bool has_lost();		
};
