#include "Library.h"

#define CUSTOMER_MAX_LENDABLES 2

/* Creates file descriptors for customer and item database */
Library::Library(std::string path) {
    inv_file = new std::fstream(path + "/items.txt", std::fstream::in | std::fstream::out);
    cust_file = new std::fstream(path + "/customers.txt");

    m_inv = new Inventory();

    std::string line_buffer;
    int b_type, b_year, b_lent_to;
    std::string b_title;

    if(!inv_file || !cust_file) {
        std::cout << "EXIT" << std::endl;
        exit(2);
    }
    else {
        while(std::getline(*inv_file, line_buffer)) {
            std::vector<std::string> tokens = tokenize(line_buffer, ':');
            b_type = stoi(tokens[0]);
            b_title = tokens[1];
            b_year = stoi(tokens[2]);
            b_lent_to = stoi(tokens[3]);
            Lendable it(b_type, b_title, b_year, b_lent_to);
            m_inv->add_item(it);
        }
    }
}

Library::~Library() {
    delete m_inv;
    delete cust_file;
    delete inv_file;
    delete m_me;
}

/* Splits a string at delim and returns a vector with the split parts (tokens) */
std::vector<std::string> Library::tokenize(std::string text, char delim) {
	std::vector<std::string> return_val;
	int prev_pos = 0;
	for(int i = 0; i < text.length(); i++) {
		if(text[i] == delim) {
			return_val.push_back(text.substr(prev_pos, i - prev_pos));
			prev_pos = i + 1; // delim wil not be part of any token
		}
	}
	return_val.push_back(text.substr(prev_pos, text.length() - prev_pos));
	return return_val;
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
    std::vector<Lendable> results;
	for(int i = 0; i < m_inv->get_items().size(); i++) {
		Lendable l = m_inv->get_items()[i];
		if(std::to_string(l.get_type()).find(expr) != std::string::npos ||
				l.get_title().find(expr) != std::string::npos ||
				std::to_string(l.get_year()).find(expr) != std::string::npos) {
			results.push_back(l);
		}
	}
    
    return results;
}

std::string Library::to_sha1_string(std::string input) {
    unsigned char hash[20]; // 160 bit buffer for SHA1 digest
    SHA1((const unsigned char *) input.c_str(), input.length(), hash);
    
    char sha1_string[41];
    for(int i = 0; i < 20; i++) {
    	int c1 = hash[i] / 16;
    	int c2 = hash[i] % 16;

		sprintf(sha1_string + i * 2, "%1x%1x", c1, c2);
    }
    sha1_string[40] = '\0';

    std::string ret = std::string(sha1_string);
    return sha1_string;
}

/* Returns 1 if credentials were valid, 0 otherwise */
int Library::check(Credentials creds) {
	std::string line_buffer;
    std::string b_username;
    std::string b_pwhash;
    
    std::string creds_pwhash = to_sha1_string(creds.password);

    while(std::getline(*cust_file, line_buffer)) {
        std::vector<std::string> tokens = tokenize(line_buffer, ':');
        b_username = tokens[0];
        b_pwhash = tokens[1];

        if(b_username.compare(creds.username) == 0 && b_pwhash.compare(creds_pwhash) == 0)
        	return 1;
    }
    cust_file->clear();
    cust_file->seekg(0);
    return 0;
}

int Library::login(Credentials creds) {
    // TODO permission level when guest or admin
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