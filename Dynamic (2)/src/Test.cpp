#include "Animal.h"
#include "Dog.h"
#include "Dragon.h"
#include "Radio.h"
#include "Door.h"

#include "DynamicObject.h"

#include <iostream>
#include <vector>

int main() {
	// Vektor mit DynamicObjects deklarieren
	std::vector<DynamicObject *> dynamic_objects;

	// Ein paar DynamicObjects in den Vektor packen
	Dog *dog1 = new Dog("Wuffy", 8, "Bernhardiner");
	dynamic_objects.push_back(dog1);
	
	Dragon *dragon1 = new Dragon("Drago", 524, 1245);
	dynamic_objects.push_back(dragon1);
	
	Door *door1 = new Door();
	dynamic_objects.push_back(door1);
	
	Radio *radio1 = new Radio();
	dynamic_objects.push_back(radio1);
	
	// Aufrufen der einzelnen Methoden
	for(int i = 0; i < dynamic_objects.size(); i++) {
		dynamic_objects[i]->init();
		dynamic_objects[i]->update();

		Dog *dog = dynamic_cast<Dog *>(dynamic_objects[i]);
		if(dog) dog->bite(dragon1);

		Dragon *dragon = dynamic_cast<Dragon *>(dynamic_objects[i]);
		if(dragon) dragon->breath_fire(dog1);
		
		Door *door = dynamic_cast<Door *>(dynamic_objects[i]);
		if(door) {
			if(door->is_opened())
				door->close();
			else
				door->open();
		}
		
		Radio *radio = dynamic_cast<Radio *>(dynamic_objects[i]);
		if(radio) radio->play_audio();
	}

	delete dog1;
	delete dragon1;
	delete door1;
	delete radio1;

	return 0;
}
