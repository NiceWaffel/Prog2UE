#include "Radio.h"

/* Konstruktor in Radio */
Radio::Radio() {
	std::cout << "Object created (" <<
		typeid(this).name() << ")!" << std::endl;
}

/* Destruktor in Radio */
Radio::~Radio() {
	std::cout << "Object deleted (" <<
		typeid(this).name() << ")!" << std::endl;
}

/* Ueberschreibt init-Methode in DynamicObject */
bool Radio::init() {
	std::cout << "Call to init in " << typeid(this).name()
		<< "!" << std::endl;
	return true;
}

/* Ueberschreibt update-Methode in DynamicObject */
void Radio::update() {
	std::cout << "Call to update in " << typeid(this).name()
		<< "!" << std::endl;
}

/* Spezialisierende Methode für Radio */
void Radio::play_audio() {
	std::cout << "Currently playing: " << m_current_track << std::endl;
}

/* Getter für den aktuellen Track */
std::string Radio::get_current_track() {
	return m_current_track;
}
