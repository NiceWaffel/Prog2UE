#include "IntArray.h"

#include <iostream>

int main() {
	IntArray a(12);

	a.set(0, 22);
	a.set(2, 44);

	std::cout << a.get(1) << std::endl;
	std::cout << a.get(2) << std::endl;

	a.resize(14);

	a.set(13, 11);

	std::cout << a.get(13) << std::endl;

	return 0;
}