#include "DummyClass.h"
#include "Array.h"
#include "TemplateArray.h"

#include <iostream>

void test0() {
	Array a(12);
	a.set(0, 22);
	a.set(2, 44);
	std::cout << a.get(1) << std::endl;
	std::cout << a.get(2) << std::endl;
	a.resize(14);
	a.set(13, 11);
	std::cout << a.get(13) << std::endl;

	std::cout << std::endl << "Float Template Array:" << std::endl;
	TemplateArray<float> ta(12);
	ta.set(0, 22.2);
	ta.set(2, 44.5);
	std::cout << ta.get(1) << std::endl;
	std::cout << ta.get(2) << std::endl;
	ta.resize(14);
	ta.set(13, 11.1);
	std::cout << ta.get(13) << std::endl;

	std::cout << std::endl << "Dummy class Template Array:" << std::endl;
	TemplateArray<Dummy> ta2(12);
	ta2.set(0, Dummy(0));
	ta2.set(2, Dummy(10));
	std::cout << ta2.get(1).dummy_function() << std::endl;
	std::cout << ta2.get(2).dummy_function() << std::endl;
	ta2.resize(14);
	ta2.set(13, Dummy(2));
	std::cout << ta2.get(13).dummy_function() << std::endl;
	std::cout << ta2.get(2).dummy_function() << std::endl;
}

void test1() {
	Array a1(12);
	a1.set(0, 22);
	a1.set(2, 44);
	std::cout << "a1: " << a1 << std::endl;

	Array a2(10);
	for(int i = 0; i < a2.getSize(); i++) {
		a2.set(i, 2);
	}
	std::cout << "a2: " << a2 << std::endl;

	std::cout << "a1 + a2: " << a1 + a2 << std::endl;

	a1++;
	std::cout << "a1++: " << a1 << std::endl;
}

int main(int argc, char **argv) {
	if(argc < 2) {
		return 1;
	}

	switch(argv[1][0]) {
		case '0':
			test0();
			break;
		case '1':
			test1();
			break;
		default:
			return 1;
	}
	
	return 0;
}
