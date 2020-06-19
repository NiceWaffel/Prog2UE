#include "Lendable.h"

Lendable::Lendable(int type, std::string title, int year, int lent_to) {
    m_type = type;
    m_title = title;
    m_year = year;
    m_lent_to = lent_to;
}

void Lendable::lend_to(int id) {
    m_lent_to = id;
}

unsigned int Lendable::get_id() {
    return m_id;
}

int Lendable::get_type() {
    return m_type;
}

std::string Lendable::get_title() {
    return m_title;
}

int Lendable::get_year() {
    return m_year;
}

int Lendable::lent_to_id() {
    return m_lent_to;
}

void Lendable::set_id(unsigned int id) {
    m_id = id;
}
