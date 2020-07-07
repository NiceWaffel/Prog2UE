#pragma once

#include <iostream>
#include <string>

#include "Animal.h"

using namespace std;

class Dog : public Animal {
	protected:
		string m_breed;
	public:
		Dog(string name, int age, string breed);
		~Dog();
		void bite(Animal *target);
		string get_breed();
};
