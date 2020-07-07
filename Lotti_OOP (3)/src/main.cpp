#include "Game.h"
#include <memory>

int main() {
	int player_count = 4;

	std::cout << "Lotti Karotti mit " << player_count << " Spielern!" << std::endl;

	Game game = Game();
	game.loop();

	/* Wird nie erreicht */
	return 0;
}
