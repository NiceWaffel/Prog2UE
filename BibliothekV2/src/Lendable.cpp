#include "Lendable.h"

Lendable::Lendable(int id) {
	m_id = id;
}

Lendable::~Lendable() {}

void Lendable::put_attribute(std::string key, std::string value) {
	m_attributes.insert_or_assign(key, value);
}

std::string Lendable::get_attribute(std::string key) {
	if(m_attributes.find(key) == m_attributes.end())
		return "unknown";
	return m_attributes[key];
}

bool Lendable::matches_expression(std::string expr) {
	if(expr == std::to_string(m_id))
		return true;
	
	for(auto iter = m_attributes.begin(); iter != m_attributes.end(); iter++) {
		if(iter->second.find(expr) != std::string::npos)
			return true;
	}
	return false;
}

int Lendable::get_id() {
	return m_id;
}
