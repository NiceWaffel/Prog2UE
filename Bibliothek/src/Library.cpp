#include "Library.h"

#define CUSTOMER_MAX_LENDABLES 2

/* Creates file descriptors for customer and item database */
Library::Library(std::string path) {
    inv_file = new std::fstream(path + "/items.txt", std::fstream::in | std::fstream::out);
    cust_file = new std::fstream(path + "/customers.txt");

    std::string line_buffer;

    int b_type, b_year, b_lent_to;
    char b_title[200];

    if(!inv_file || !cust_file) {
        std::cout << "EXIT" << std::endl;
        exit(2);
    }
    else {
        while(std::getline(*inv_file, line_buffer)) {
            sscanf(line_buffer.c_str(), "%d:%200s:%d:%d", &b_type, b_title, &b_year, &b_lent_to);
            Lendable it(b_type, b_title, b_year, b_lent_to);
            m_inv->add_item(it);
        }
    }
}

Library::~Library() {
    delete m_inv;
    delete cust_file;
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
    std::vector<Lendable> results;
    return results;
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