#pragma once

#include <string>

struct Book {
    unsigned int ID;
    std::string title;
    std::string author;
    int year;
    int lent_to;
};