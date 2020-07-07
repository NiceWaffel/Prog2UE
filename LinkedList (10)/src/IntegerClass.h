#pragma once

#include <iostream>

class IntegerClass {
	public:
		IntegerClass(int a);
		IntegerClass() {
			m_a = 0;
		}
		
		friend std::ostream& operator<<(std::ostream& os, IntegerClass& e);

	private:
		int m_a;
};

