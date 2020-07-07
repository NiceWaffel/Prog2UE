#include "IntegerClass.h"

IntegerClass::IntegerClass(int a) {
	m_a = a;
}

std::ostream& operator<<(std::ostream& os, IntegerClass& e) {
	os << e.m_a ;
	return os;
}
