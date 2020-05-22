#include "Player.h"

Player::Player() {
    memset(m_positions, POS_UNSTARTED, 4);
    m_death_count = 0;
}

Player::~Player() {}

void Player::move(int offset) {
    int fig;
    do {
        fig = std::rand() % 4;
    } while(Player::m_positions[fig] == POS_DEAD);

    Player::m_positions[fig] += offset;

    // Wenn das letzte Feld erreicht ist, gewinnt der aktuelle Spieler
    if(Player::m_positions[fig] == 27)
        Player::m_won = 1;

    std::cout << "Figure " << fig << " moves by " << offset << std::endl;
}

void Player::die(int index) {
    Player::m_positions[index] = POS_DEAD;
    m_death_count++;
}

int *Player::get_positions() {
    return Player::m_positions;
}

int Player::get_death_count() {
    return Player::m_death_count;
}

int Player::has_won() {
    return Player::m_won;
}
