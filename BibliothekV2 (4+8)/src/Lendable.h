#pragma once

#include <string>
#include <map>

class Lendable {
	private:
		int m_id;
		std::map<std::string, std::string> m_attributes;
	public:
		Lendable() = default;
		Lendable(int id);
		~Lendable();
		void put_attribute(std::string key, std::string value);
		std::string get_attribute(std::string key);
		bool matches_expression(std::string expr);

		int get_id();
};