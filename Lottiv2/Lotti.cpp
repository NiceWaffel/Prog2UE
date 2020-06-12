#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#define PLAYER_COUNT 4
#define NO_HOLE -1
#define CARROT_POS 25
#define POS_DEAD -1

struct Player {
	int pos[4];
	bool lost;
};

int hole_positions[] = {NO_HOLE, 13, 25, 16, 23, 4, 21, 7, 19, 10};
int hole_index;
Player players[PLAYER_COUNT];
int cur_player = 0;

/* Aktualisiert die Lochposition */
void turn_carrot() {
    std::cout << "Spieler " << cur_player << " dreht die Karotte" << std::endl;
    
    hole_index++;
    hole_index %= 11;
}

/* Prueft, ob ein Feld mit einer Figur besetzt ist */
bool occupied(int pos) {
	for(int i = 0; i < PLAYER_COUNT; i++) {
		if(players[i].pos[0] == pos ||
				players[i].pos[1] == pos ||
				players[i].pos[2] == pos ||
				players[i].pos[3] == pos)
			return true;
	}
	return false;
}

/* Bewegt Figur fig des Spielers an index player in players[] um rel_pos positionen */
void move(int player, int fig, int rel_pos) {
	int new_pos = players[player].pos[fig] + rel_pos;

	while(occupied(new_pos)) {
		new_pos++;
	}
	players[player].pos[fig] = new_pos;
	std::cout << "Spieler " << player << " zieht Figur " << fig << " auf Position " << new_pos << std::endl;
}

/* When a player has lost all its figures it lost overall */
void check_lost(int player) {
	if(players[player].pos[0] == POS_DEAD &&
			players[player].pos[1] == POS_DEAD &&
			players[player].pos[2] == POS_DEAD &&
			players[player].pos[3] == POS_DEAD) {
		std::cout << "Spieler " << player << " hat verloren!" << std::endl;
		players[player].lost = true;
	}
}

/* Prueft ob alle Spieler verloren haben und beendet das Spiel wenndem so ist */
void check_all_dead() {
	bool someone_lives = false;
	for(int i = 0; i < PLAYER_COUNT; i++) {
		if(!players[i].lost)
			someone_lives = true;
	}
	if(someone_lives)
		return;
	
    std::cout << "Alle Spieler haben verloren. Die Karotte lebt!" << std::endl;
	exit(0);
}

void loop() {
    while(1) {
        std::cout << "Spieler " << cur_player << " ist an der Reihe" << std::endl;
        
		/* Eine Karte ziehen und entweder die Karotte drehen oder den Spieler bewegen */
        int card = rand() % 4;
        int figure;
        if(card == 0) {
            turn_carrot();
        }
        else {
	        /* Die Figur waehlen (zufaellig) */
	        for(int i = 0; i < 4; i++) {
	        	figure = rand() % 4;
	        	if(!(players[cur_player].pos[figure] == POS_DEAD))
	        		break;
	        }
	        
            move(cur_player, figure, card);

			/* Checkt ob die bewegte Figur in ein Loch gefallen ist oder gewonnen hat */
            if(players[cur_player].pos[figure] == hole_positions[hole_index]) {
            	players[cur_player].pos[figure] = POS_DEAD;
            	std::cout << "Spieler " << cur_player << " verliert Figur " << figure << std::endl;
            	check_lost(cur_player);
            }
            else if(players[cur_player].pos[figure] == CARROT_POS) {
            	std::cout << "Spieler " << cur_player << " hat gewonnen!" << std::endl;
            	exit(0);
            }
        }

        check_all_dead();

        /* Den naechsten Spieler waehlen */
        for(int i = 0; i < PLAYER_COUNT; i++) {
            cur_player++;
            cur_player %= PLAYER_COUNT;
            if(!players[cur_player].lost)
            	break;
        }
    }
}

int main() {
	std::cout << "Lotti Karotti mit " << PLAYER_COUNT << " Spielern" << std::endl;

	/* Variablen initialisieren */
	hole_index = 0;
	for(int i = 0; i < PLAYER_COUNT; i++) {
		players[i] = Player{{0, 0, 0, 0}, false};
	}
	srand(time(NULL));

	/* Start des Game-loops, welche alles weitere handled */
	loop();

	/* Wird nie erreicht */
	return 0;
}
