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
    	// Has to be sorted
        std::multimap<Lendable> m_inventory;

        // Stores Customer according to their ID
        std::map<Customer> m_customers;

        // The currently logged in customer (or admin/guest according to flags)
		Customer m_user;
        
        std::fstream *inv_file;
        std::fstream *cust_file;

        std::string to_sha1_string(std::string input);
        std::vector<std::string> tokenize(std::string text, char delim);
        int check(Credentials creds);
		void load_inventory_from_file();
    public:
        Library();
        ~Library();
		
        int login(Credentials creds);
        
        int lend(unsigned int lendable_id);
        int give_back(unsigned int lendable_id);
        
        std::vector<Lendable> search(std::string expr);

        Customer get_login_customer();
        Customer get_customer(int customer_id);
};