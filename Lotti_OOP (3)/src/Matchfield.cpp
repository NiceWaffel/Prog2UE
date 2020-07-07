#include "Matchfield.h"

Matchfield::Matchfield() {
	current_hole = 0;
	for(int i = 0; i < CARROT_POS; i++) {
		occupied[i] = false;
	}
}

bool Matchfield::is_occupied(int idx) {
	return occupied[idx];
}

void Matchfield::set_occupied(int idx, bool occu) {
	occupied[idx] = occu;
}

void Matchfield::turn_carrot() {
	current_hole++;
	current_hole %= 11;
}

int Matchfield::get_hole_pos() {
	return hole_pos[current_hole];
}

