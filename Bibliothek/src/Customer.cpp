#include "Customer.h"

/* Getter for the list of currently lent books */
std::vector<Book> Customer::get_currently_lent_books() {
    return m_currently_lent;
}

/* Getter for the customer's ID */
int Customer::get_id() {
    return m_customer_ID;
}