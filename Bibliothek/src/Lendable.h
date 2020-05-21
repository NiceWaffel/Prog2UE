#pragma once

#include <string>

#define LENDABLE_TYPE_BOOK 1
#define LENDABLE_TYPE_VIDEOGAME 2
#define LENDABLE_TYPE_AUDIOBOOK 3

class Lendable {
    private:
        unsigned int m_id;
        int m_type;
        std::string m_title;
        int m_year;
        int m_lent_to;
    public:
        Lendable(int type, std::string title, int year, int lend_to);
        // Default destructor here

        int lend_to(int id);

        // Getters and Setters
        unsigned int get_id();
        int get_type();
        std::string get_title();
        int get_year();
        int lent_to_id();

        void set_id(unsigned int id);
};