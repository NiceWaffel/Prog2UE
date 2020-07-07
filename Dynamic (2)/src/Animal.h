#pragma once

#include <iostream>
#include <string>
#include "DynamicObject.h"

using namespace std;

class Animal : public DynamicObject {
	protected:
		string m_name;
		int m_age;
	public:
		Animal(string name, int age);
		~Animal();
		bool init();
		void update();
		string get_name();
		int get_age();
};
