#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Lendable.h"
#include "Customer.h"

class Inventory {
    private:
        std::vector<Lendable> m_items;

    public:
        void add_item(Lendable item);
        void remove_item(unsigned int id);
        int lend_item(unsigned int item_id, Customer *customer);
        std::vector<Lendable> get_items();
};