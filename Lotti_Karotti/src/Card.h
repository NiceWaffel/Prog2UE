#pragma once

#include <random>

class Card {
    private:
        int m_value;

    public:
        Card();
        ~Card();
        int get_value();
};
