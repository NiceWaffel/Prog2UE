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

        void print_error();
    public:
        Library();
        ~Library();
        int lend_book(int book_id, int customer_id);
        std::vector<Book> search();
        int check_creds(Credentials creds);

};