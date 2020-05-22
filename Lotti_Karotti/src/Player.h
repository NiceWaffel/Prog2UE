#pragma once

#include <random>
#include <iostream>
#include <string.h>

#define POS_UNSTARTED 0
#define POS_DEAD -1

class Player {

    private:
        int m_positions[4];
        int m_death_count;
        int m_won;

    public:
        Player();
        ~Player();
        void move(int offset);
        void die(int index);
        int *get_positions();
        int get_death_count();
        int has_won();
};
