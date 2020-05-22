#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <ctime>

#include "Player.h"
#include "Card.h"

#define NO_HOLE -2

Player players[4];
int current_player = 0;
Card *current_card;
int hole_index;
int hole_positions[] = {NO_HOLE, 13, 25, 16, 23, 4, 21, 7, 19, 10};
int lost = 0;

void quit() {
    std::cout << "All Players lost :(" << std::endl;
    exit(0);
}

void win() {
    std::cout << "Player " << current_player << " wins" << std::endl;
    exit(0);
}

void lose(int p_index) {
    if(!(lost & (1 << p_index)))
        std::cout << "Player " << p_index << " lost" << std::endl;
    lost |= 1 << p_index;
    if(lost == 15)
        quit();
}

void turn_carrot() {
    hole_index++;
    hole_index %= 11;

    std::cout << "Player " << current_player << " turns the carrot" << std::endl;
}

void check_death() {
    for(int i = 0; i < 4; i++) {
        int *positions = players[i].get_positions();
        for(int j = 0; j < 4; j++) {
            if(positions[j] == hole_positions[hole_index]) {
	    	players[i].die(j);
		std::cout << "Player " << i << " loses its Figure " << j << std::endl;
	    }
        }
        if(players[i].get_death_count() == 4)
            lose(i);
    }
}

void loop() {
    while(1) {
        std::cout << "Player " << current_player << " is playing" << std::endl;

        current_card = new Card();
        if(current_card->get_value() == 4) {
            turn_carrot();
        } else {
            players[current_player].move(current_card->get_value());
        }
        do {
            current_player++;
            current_player %= 4;
        } while(lost & (1 << current_player));

        delete current_card;

        check_death();

        if(players[current_player].has_won())
            win();
    }
}

int main(int argc, char **argv) {
    std::cout << "Lotti Karotti mit 4 Spielern!" << std::endl << std::endl;
    srand(time(NULL));
    loop();
}
