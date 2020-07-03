#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

#include <openssl/sha.h>

#include "Customer.h"

/* Doesn't have to be changeable according to instructions */
#define CUSTOMER_MAX_LENDABLES 2

class Library {
    private:
    	// Sorted by design, key is published date
        std::map<int, Lendable> m_inventory;

        // Stores Customer according to their ID
        std::map<int, Customer> m_customers;

        // The currently logged in customer (or admin/guest according to flags)
		Customer m_user;
        
        std::fstream *inv_file;
        std::fstream *cust_file;

        std::string to_sha1_string(std::string input);
        std::vector<std::string> tokenize(std::string text, char delim);
        
		void load_inventory_from_file();
		void load_customers_from_file();
    public:
	    struct Credentials {
	        std::string username;
	        std::string password;
	    };
	    
        Library(std::string inv_path, std::string cust_path);
        ~Library();
		
        bool login(Credentials creds);
        
        bool lend(unsigned int lendable_id);
        bool give_back(unsigned int lendable_id);
        
        std::vector<Lendable> search(std::string expr);

        Customer get_user();
        Customer get_customer(int customer_id);
};