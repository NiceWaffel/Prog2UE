#include "Library.h"

/* Splits a string at delim and returns a vector with the split parts (tokens)
 * Tokens of length 0 are ignored and will not end up in the return vector
 * Whitespace does not get trimmed away */
std::vector<std::string> Library::tokenize(std::string text, char delim) {
    std::vector<std::string> return_val;
    int prev_pos = 0;
    for(int i = 0; i < text.length(); i++) {
        if(text[i] == delim) {
        	std::string substr = text.substr(prev_pos, i - prev_pos);
        	if(substr.length() > 0)
            	return_val.push_back(substr);
			prev_pos = i + 1; // delim wil not be part of any token
    	}
    }
    return_val.push_back(text.substr(prev_pos, text.length() - prev_pos));
    return return_val;
}

/* Converts an input string into a hex SHA1 message digest string */  
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

/* Loads inventory from file specified in constructor
 * ':' in any inside part of a token will lead to broken behavior */
void Library::load_inventory_from_file() {
	if(!inv_file) {
		// TODO throw exception
	}

	std::string line_buffer = "";
	while(std::getline(*inv_file, line_buffer)) {
        std::vector<std::string> tokens = tokenize(line_buffer, ':');
        if(tokens.size() < 2)
        	continue;

        // First token has to be the id
        int item_id = stoi(tokens[0]);
        tokens.erase(tokens.begin());
        
        Lendable item(item_id);
        
        // Get all attributes for all tokens
        for(auto token : tokens) {
        	std::vector<std::string> key_value_pair = tokenize(token, '=');
        	if(key_value_pair.size() < 2)
        		continue;

			// Everything before the first '=' is the token key
        	// Everything behind the first '=' is the token value
        	std::string key = key_value_pair[0];
        	std::string value = key_value_pair[1];
        	for(int i = 2; i < key_value_pair.size(); i++) {
        		value += "=";
        		value += key_value_pair[i];
        	}

        	item.put_attribute(key, value);
        }
        m_inventory.insert_or_assign(item_id, item);
    }
}

void Library::load_customers_from_file() {
	if(!cust_file) {
		// TODO throw exception
	}
	std::string line_buffer;
	int b_id, b_perm;
	std::string b_uname, b_pwhash;

	while(std::getline(*cust_file, line_buffer)) {
        std::vector<std::string> tokens = tokenize(line_buffer, ':');
        if(tokens.size() < 4)
        	continue;
        
        b_id = stoi(tokens[0]);
        b_uname = tokens[1];
        b_perm = stoi(tokens[2]);
        b_pwhash = tokens[3];
        
        Customer cust(b_id, b_perm, b_uname, b_pwhash);
        m_customers.insert_or_assign(b_id, cust);
    }	
}

Library::Library(std::string inv_path, std::string cust_path) {
	// Open files and call load functions
	inv_file = new std::fstream(inv_path, std::fstream::in | std::fstream::out);
	cust_file = new std::fstream(cust_path, std::fstream::in | std::fstream::out);

	load_inventory_from_file();
	load_customers_from_file();
}

Library::~Library() {
	// Close open files
	if(inv_file) {
		inv_file->close();
		delete inv_file;
	}
	if(cust_file) {
		cust_file->close();
		delete cust_file;
	}
}

/* Tries to log in the user with the given credentials
 * Returns false if login failed for any reason, true if login was successful */
bool Library::login(Credentials creds) {
	std::string creds_pwhash = to_sha1_string(creds.password);

	for(auto iter = m_customers.begin(); iter != m_customers.end(); iter++) {
		if(iter->second.get_username() == creds.username &&
				iter->second.get_pwhash() == creds_pwhash) {
			// Credentials are valid
			m_user = iter->second;
			return true;
		}
	}
	
	return false;
}

bool Library::lend(unsigned int lendable_id) {
	// check if lend to someone else than library
	// error message if that's the case
	// TODO
	return true;
}

bool Library::give_back(unsigned int lendable_id) {
	// TODO
	return true;
}

std::vector<Lendable> Library::search(std::string expr) {
	std::vector<Lendable> result;

	// search through all items
	for(auto iter = m_inventory.begin(); iter != m_inventory.end(); iter++) {
		if(iter->second.matches_expression(expr)) {
			Lendable l = iter->second;
			result.push_back(l);
		}
	}
	return result;
}

Customer Library::get_user() {
	return m_user;
}

Customer Library::get_customer(int customer_id) {
	return m_customers[customer_id];
}
