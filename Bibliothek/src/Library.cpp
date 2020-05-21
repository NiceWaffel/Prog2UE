#include "Library.h"

Library::Library() {
    // TODO
}

Library::~Library() {
    // TODO
}

int Library::login(Credentials creds) {
    // TODO
    if(1) {
        m_login_username = creds.username;
        return 1;
    }
    return 0;
}

std::string Library::get_login_name() {
    return m_login_username;
}

std::string Library::get_customer_name(int id) {
    for(Customer& cust : m_customers) {
        if(cust.get_id() == id)
            return cust.get_name();
    }
    return "Invalid ID";
}
