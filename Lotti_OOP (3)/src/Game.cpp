#include "Game.h"

Game::Game() {
	/* Spielfeld initialisieren */
	matchfield = std::make_shared<Matchfield>();
	for(int i = 0; i < PLAYER_COUNT; i++) {
		Player p(i, this);
		players.push_back(p);
	}
}

/*
 * Ueberprueft ob alle Spieler verloren haben und beendet das Spiel wenn dem so ist
 */
void Game::check_all_dead() {
	bool someone_lives = false;
	for(int i = 0; i < PLAYER_COUNT; i++) {
		if(!players[i].has_lost())
			someone_lives = true;
	}
	if(someone_lives)
		return;

	std::cout << "Alle Spieler haben verloren. Die Karotte lebt!" << std::endl;
	exit(0);
}

/*
 * Dreht die Karotte und ueberprueft ob Figuren ins Loch gefallen sind
 * Da Zugriff auf alle Spieler noetig ist die Implementation hier am einfachsten,
 * selbst wenn sie vielleicht in Player sinnvoller waere
 */
void Game::turn_carrot() {
	matchfield->turn_carrot();
	for(int i = 0; i < PLAYER_COUNT; i++) {
		players[i].check_death();
	}
}

/*
 * Die Haupt-Gameloop.
 * Aktualisiert jetzt Runde den aktuellen Spieler und fuehrt dessen move() methode aus
 * Falls alle Spieler verloren haben endet das Spiel
 */
void Game::loop() {
	int cur_player = 0;
	
	while(1) {
        std::cout << "Spieler " << cur_player << " ist an der Reihe" << std::endl;
        
		/* Der aktuelle Spieler macht seinen Zug */
        players[cur_player].move();

        check_all_dead();

        /* Den naechsten Spieler waehlen */
        for(int i = 0; i < PLAYER_COUNT; i++) {
            cur_player++;
            cur_player %= PLAYER_COUNT;
            if(!players[cur_player].has_lost())
            	break;
        }
    }
}

std::shared_ptr<Matchfield> Game::get_matchfield() {
	return matchfield;
}

CardStack Game::get_card_stack() {
	return card_stack;
}
