#include "Inventory.h"

/* Adds a book the the list of books and returns it's assigned ID */
int Inventory::add_book(std::string title, std::string author, int year) {
    Book b;
    b.title = title;
    b.author = author;
    b.year = year;
    b.lent_to = 0; // lent to noone for now

    unsigned int id = std::rand();
    id = (id << 16) + std::rand();
    // FIXME No check for duplicate ids

    // TODO add in ordered fashion
    m_books.push_back(b);

    return id;
}

/* Removes a book with a given id */
void Inventory::remove_book(int id) {

}

/* Returns 0 on success and 1 on any
 * error (book was not found or already lent to someone) */
int Inventory::lend_book(int id, Customer customer) {
    for(int i = 0; i < m_books.size(); i++) {
        if(id == m_books[i].ID && m_books[i].lent_to == 0) {
            m_books[i].lent_to = customer.get_id();
            return 0;
        }
    }
    return 1;
}

/* Getter for the whole list of books */
std::vector<Book> Inventory::get_books() {
    return m_books;
}