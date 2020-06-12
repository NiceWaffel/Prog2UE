#pragma once

#include "Matchfield.h"
#include "Player.h"
#include "CardStack.h"

#include <memory>
#include <iostream>
#include <vector>

#define PLAYER_COUNT 4

class Player;

class Game {
	private:
		std::vector<Player> players;
		std::shared_ptr<Matchfield> matchfield;
		CardStack card_stack;

		void check_all_dead();

	public:
		Game();
		~Game() = default;
		void loop();
		void turn_carrot();
		CardStack get_card_stack();
		std::shared_ptr<Matchfield> get_matchfield();
};
