#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Lendable.h"

class Customer {
    private:
        std::vector<unsigned int> m_currently_lent;
        int m_customer_ID;
        std::string m_name;

    public:
        Customer(int id, std::string name, std::vector<unsigned int> lent);
        std::vector<unsigned int> get_currently_lent();
        void add_item(unsigned int id);
        void remove_item(unsigned int id);
        int get_id();
        std::string get_name();
};