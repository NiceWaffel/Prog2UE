#include "Card.h"

Card::Card() {
    int rand = std::rand() % 4;
    m_value = rand + 1;
}

Card::~Card() {}

int Card::get_value() {
    return Card::m_value;
}
