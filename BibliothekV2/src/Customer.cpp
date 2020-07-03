#include "Customer.h"

Customer::Customer(int id, int permission_level, std::string username, std::string pwhash) {
	m_id = id;
	m_permission_level = permission_level;
	m_username = username;
	m_pwhash = pwhash;
}

Customer::~Customer() {}

int Customer::get_id() {
	return m_id;
}

int Customer::get_permission_level() {
	return m_permission_level;
}

std::string Customer::get_username() {
	return m_username;
}

std::string Customer::get_pwhash() {
	return m_pwhash;
}
