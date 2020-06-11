#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

#include <openssl/sha.h>

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

		std::string to_sha1_string(std::string input);
        int check(Credentials creds);
        std::vector<std::string> tokenize(std::string text, char delim);
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