#include "Dragon.h"
#include <iostream>

/* Konstruktor für Dragon,
 * ruft den Konstruktor von Animal auf */
Dragon::Dragon(string name, int age, int fire_temp) : Animal(name, age) {
	m_fire_temp = fire_temp;
	cout << "Object " << m_name << " created (" <<
		typeid(this).name() << ")!" << endl;
}

/* Destruktor von Dragon */
Dragon::~Dragon() {
	cout << "Object " << m_name << " deleted (" <<
		typeid(this).name() << ")!" << endl;
}

/* Eine individuelle Methode für Dragon */
void Dragon::breath_fire(Animal *target) {
	cout << "Dragon " << m_name << " grills " << target->get_name() <<
	       	" (" << typeid(target).name() << ")" << endl;
}

/* Getter für die Feuertemperatur */
string Dragon::get_fire_temp() {
	return m_fire_temp;
}
