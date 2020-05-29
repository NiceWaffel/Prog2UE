#include <iostream>
#include "Animal.h"

using namespace std;

/* Konstruktor für Animal */
Animal::Animal(string name, int age) {
	m_name = name;
	m_age = age;
	cout << "Object " << m_name << " created (" <<
		typeid(this).name() << ")!" << endl;
}

/* Destruktor für Animal */
Animal::~Animal() {
	cout << "Object " << m_name << " deleted (" <<
		typeid(this).name() << ")!" << endl;
}

/* Init Methode in Animal */
bool Animal::init() {
	cout << "Call to init in " << typeid(this).name() <<
		"!" << endl;
	return true;
}

/* Update Methode in Animal */
void Animal::update() {
	cout << "Call to update in " << typeid(this).name() <<
		"!" << endl;
}

/* Getter für den Namen des Animal */
string Animal::get_name() {
	return m_name;
}

/* Getter für das Alter des Animal */
int Animal::get_age() {
	return m_age;
}
