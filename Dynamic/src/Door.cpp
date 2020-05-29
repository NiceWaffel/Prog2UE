#include "Door.h"

/* Konstruktor in Door */
Door::Door() {
	std::cout << "Object created (" <<
		typeid(this).name() << ")!" << std::endl;
}

/* Destruktor in Door */
Door::~Door() {
	std::cout << "Object deleted (" <<
		typeid(this).name() << ")!" << std::endl;
}

/* Ueberschreibt init-Methode in DynamicObject */
bool Door::init() {
	std::cout << "Call to init in " << typeid(this).name()
		<< "!" << std::endl;
	return true;
}

/* Ueberschreibt update-Methode in DynamicObject */
void Door::update() {
	std::cout << "Call to update in " << typeid(this).name()
		<< "!" << std::endl;
}

/* Spezialisierende Methode für Door */
void Door::open() {
	std::cout << "Door opened" << std::endl;
}

/* Spezialisierende Methode für Door */
void Door::close() {
	std::cout << "Door closed" << std::endl;
}

/* Getter für den status 'offen' */
bool Door::is_opened() {
	return m_opened;
}
