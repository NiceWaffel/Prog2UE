#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Book.h"
#include "Customer.h"

class Inventory {
    private:
        std::vector<Book> m_books;

    public:
        int add_book(std::string title, std::string author, int year);
        void remove_book(int id);
        int lend_book(int id, Customer customer);
        std::vector<Book> get_books();
};