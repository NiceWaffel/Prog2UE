#include "Lendable.h"

Lendable::Lendable(int type, std::string title, int year, int lent_to) {
    m_type = type;
    m_title = title;
    m_year = year;
    m_lent_to = lent_to;
}

/* Returns 1 on success and 0 on failure
 * (Usually when book is already lent to someone) */
int Lendable::lend_to(int id) {
    if(m_lent_to == 0) { // Currently in Library
        m_lent_to = id;
        return 1;
    }
    else if(id == 0) { // Give back to Library
        m_lent_to = 0;
        return 1;
    }
    return 0;
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