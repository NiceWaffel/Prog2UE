#pragma once

#include <string>
#include <vector>
#include <Lendable.h>

class Customer {
	private:
		int m_id;
		int m_permission_level;
		std::string m_username;
		std::string m_pwhash;
	public:
		Customer() = default;
		Customer(int id, int permission_level, std::string username, std::string pwhash);
		~Customer();

		int get_id();
		int get_permission_level();
		std::string get_username();
		std::string get_pwhash();
};