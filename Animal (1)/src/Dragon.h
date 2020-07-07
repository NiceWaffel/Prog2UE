#pragma once

#include <iostream>
#include <string>

#include "Animal.h"

using namespace std;

class Dragon : public Animal {
	protected:
		string m_fire_temp;
	public:
		Dragon(string name, int age, int fire_temp);
		~Dragon();
		void breath_fire(Animal *target);
		string get_fire_temp();
};
