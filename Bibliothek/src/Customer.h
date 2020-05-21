#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Lendable.h"
#include "Person.h"

class Customer : public Person {
    private:
        std::vector<unsigned int> m_currently_lent;
        int m_customer_ID;

    public:
        std::vector<unsigned int> get_currently_lent();
        void add_item(int id);
        void remove_item(int id);
        int get_id();
};