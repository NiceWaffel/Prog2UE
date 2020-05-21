#pragma once

#include <iostream>
#include "Inventory.h"

struct Credentials {
    std::string username;
    std::string password;
};

class Library {
    private:
        Inventory m_inv;
        std::vector<Customer> m_customers;

        std::string m_login_username;
    public:
        Library();
        ~Library();
        int lend(int lendable_id, int customer_id);
        std::vector<Lendable> search();
        int login(Credentials creds);

        std::string get_login_name();
        std::string get_customer_name(int id);
};