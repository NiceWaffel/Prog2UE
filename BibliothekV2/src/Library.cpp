#include "Library.h"

/* Doesn't have to be changeable according to instructions */
#define CUSTOMER_MAX_LENDABLES 2

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

void Library::load_inventory_from_file() {
	if(!inv_file)
		return;

	// TODO
}

Library::Library(std::string inv_path, std::string cust_path) {
	// TODO open files and call load_inventory_from_file
}

Library::~Library() {
	// Close open files
	inv_file->close();
	cust_file->close();
	delete inv_file;
	delete cust_file;
}

/* Tries to log in the user with the given credentials
 * Returns false if login failed for any reason, true if login was successful */
bool Library::login(Credentials creds) {
	// TODO
}

Customer Library::get_login_customer() {
	// TODO
}

Customer Library::get_customer(int customer_id) {
	// TODO
}
