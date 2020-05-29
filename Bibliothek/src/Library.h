#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "Inventory.h"

struct Credentials {
    std::string username;
    std::string password;
};

class Library {
    private:
        Inventory *m_inv;
        Customer *m_me;
        std::fstream *inv_file;
        std::fstream *cust_file;

        int check(Credentials creds);
    public:
        Library(std::string path);
        ~Library();
        int lend(unsigned int lendable_id);
        int give_back(unsigned int lendable_id);
        std::vector<Lendable> search(std::string expr);
        int login(Credentials creds);

        std::string get_login_name();
        std::string get_customer_name(int id);
        int get_my_id();
};