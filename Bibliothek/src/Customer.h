#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "Person.h"

class Customer : public Person {
    private:
        std::vector<Book> m_currently_lent;
        int m_customer_ID;

    public:
        std::vector<Book> get_currently_lent_books();
        int get_id();
};