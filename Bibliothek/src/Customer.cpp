#include "Customer.h"

/* Getter for the list of currently lent books */
std::vector<unsigned int> Customer::get_currently_lent() {
    return m_currently_lent;
}

void Customer::add_item(int id) {
    m_currently_lent.push_back(id);
}

void Customer::remove_item(int id) {
    for(int i = 0; i < m_currently_lent.size(); i++) {
        if(m_currently_lent[i] == id) {
            m_currently_lent.erase(m_currently_lent.begin() + i);
            break;
        }
    }
}

/* Getter for the customer's ID */
int Customer::get_id() {
    return m_customer_ID;
}