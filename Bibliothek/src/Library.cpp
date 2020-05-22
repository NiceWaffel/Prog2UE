#include "Library.h"

#define CUSTOMER_MAX_LENDABLES 2

/* Creates file descriptors for customer and item database */
Library::Library(std::string path) {
    inv_file = new std::fstream(path + "/items.txt", std::fstream::in | std::fstream::out);
    cust_file = new std::fstream(path + "/customers.txt");

    char type_buffer[20];
    char title_buffer[200];
    char year_buffer[5];
    char lent_to_buffer[20];

    if(!inv_file || !cust_file) {
        exit(2);
    }
    else {
        while(!inv_file->eof()) {
            // read info into buffers
            inv_file->get(type_buffer, 20, ':');
            inv_file->get(title_buffer, 200, ':');
            inv_file->get(year_buffer, 5, ':');
            inv_file->get(lent_to_buffer, 20, ':');

            // TODO create items and save in m_items
        }
    }
}

Library::~Library() {
    delete m_inv;
    delete m_me;
}

/* Returns 1 on success, 0 otherwise */
int Library::lend(unsigned int lendable_id) {
    if(m_me->get_currently_lent().size() < CUSTOMER_MAX_LENDABLES)
        return m_inv->lend_item(lendable_id, m_me);
    return 0;
}

/* Returns 1 on success, 0 otherwise */
int Library::give_back(unsigned int lendable_id) {
    m_me->remove_item(lendable_id); // Remove from Customer
    m_inv->lend_item(lendable_id, 0); // Give back to library
    return 1;
}

std::vector<Lendable> Library::search(std::string expr) {
    // TODO
    return m_inv->get_items();
}

/* Returns 1 if credentials were valid, 0 otherwise */
int Library::check(Credentials creds) {
    // TODO check credentials
    return 1;
}

int Library::login(Credentials creds) {
    // TODO
    if(check(creds)) {
        std::vector<unsigned int> lent;
        m_me = new Customer(1, creds.username, lent);
        return 1;
    }
    return 0;
}

std::string Library::get_login_name() {
    return m_me->get_name();
}

std::string Library::get_customer_name(int id) {
    // TODO
    return "Not implemented";
}

int Library::get_my_id() {
    return m_me->get_id();
}