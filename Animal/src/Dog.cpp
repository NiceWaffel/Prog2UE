#include "Dog.h"
#include <iostream>

/* Konstruktor für Dog, ruft den Superkonstruktor Animal() auf */
Dog::Dog(string name, int age, string breed) : Animal(name, age) {
	m_breed = breed;
	cout << "Object " << m_name << " created (" <<
		typeid(this).name() << ")!" << endl;
}

/* Destruktor für Dog, benötigt keinen super call, da
 * der Destruktor keine Argumente weitergeben muss */
Dog::~Dog() {
	cout << "Object " << m_name << " deleted (" <<
		typeid(this).name() << ")!" << endl;
}

/* Eine individuelle Methode von Dog */
void Dog::bite(Animal *target) {
	cout << "Dog " << m_name << " bites " << target->get_name() <<
	       	" (" << typeid(target).name() << ")" << endl;
}

/* Getter für die Hunderasse (breed) */
string Dog::get_breed() {
	return m_breed;
}
