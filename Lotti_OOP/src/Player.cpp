#include "Player.h"

Player::Player(int id, Game *game) {
	// Alle Figuren starten bei 0
	for(int i = 0; i < FIGURE_COUNT; i++) {
		m_figures[i] = 0;
	}
	lost = false;

	this->id = id;
	this->game = game;
}

void Player::win() {
	std::cout << "Spieler " << id << " hat gewonnen!" << std::endl;
	exit(0);
}

void Player::move_fig(int fig, int rel_pos) {

	// Berechnung der neuen Position
	int new_pos = m_figures[fig] + rel_pos;
	while(game->get_matchfield()->is_occupied(new_pos)) {
		new_pos++;
	}

	if(new_pos == CARROT_POS) {
		win();
	}
	else if(new_pos > CARROT_POS) { // Wenn der Spieler ueber die Karotte hinausschiesst
		new_pos = m_figures[fig];
		return;
	}

	// Feldbesetzung aktualisieren
	game->get_matchfield()->set_occupied(m_figures[fig], false);
	game->get_matchfield()->set_occupied(new_pos, true);

	// Figur an neue Position setzen
	m_figures[fig] = new_pos;
	std::cout << "Spieler " << id << " zieht Figur " << fig << " auf " << new_pos << std::endl;
}

void Player::check_death() {
	bool a_figure_alive = false;
	for(int i = 0; i < FIGURE_COUNT; i++) {
	 	// POS_DEAD und NO_HOLE sind identisch, sodass die Nachricht faelschlicherweise
	 	// doppelt gedruckt werden kann
		if(m_figures[i] == game->get_matchfield()->get_hole_pos()) {
			m_figures[i] = POS_DEAD;
			std::cout << "Spieler " << id << " verliert Figur " << i << std::endl;
		}
		else if(m_figures[i] != POS_DEAD)
			a_figure_alive = true;
	}
	if(!a_figure_alive) {
		lost = true;
		std::cout << "Spieler " << id << " hat verloren!" << std::endl;
	}
}

/*
 * Fuehrt fuer den Spieler einen Spielzug aus.
 * Der Spieler zieht eine Karte und bewegt eine der Figuren
 * oder dreht die Karotte
 */
void Player::move() {
	// unnoetiger error-check
	if(lost)
		return;

	// Karte ziehen und zu bewegende Figur auswaehlen
	int card = game->get_card_stack().draw();
	int fig = rand() % FIGURE_COUNT;
	for(int i = 0; i < 4; i++) {
       	fig = rand() % 4;
       	if(!(m_figures[fig] == POS_DEAD))
       		break;
	}

	switch(card) {
		case CardStack::SPIN:
			game->turn_carrot();
			std::cout << "Spieler " << id << " dreht die Karotte!" << std::endl;
			break;
		case CardStack::ONE:
			move_fig(fig, 1);
			break;
		case CardStack::TWO:
			move_fig(fig, 2);
			break;
		case CardStack::THREE:
			move_fig(fig, 3);
			break;
		default:
			break;
	}
}

bool Player::has_lost() {
	return lost;
}
