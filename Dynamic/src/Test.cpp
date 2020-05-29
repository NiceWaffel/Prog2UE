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
	std::vector<DynamicObject> dynamic_objects;

	// Ein paar DynamicObjects in den Vektor packen
	Dog dog1("Wuffy", 8, "Bernhardiner");
	dynamic_objects.push_back(dog1);
	
	Dragon dragon1("Drago", 524, 1245);
	dynamic_objects.push_back(dragon1);
	
	Door door1();
	dynamic_objects.push_back(door1);
	
	Radio radio1();
	dynamic_objects.push_back(radio1);
	
	// Aufrufen der einzelnen Methoden
	for(int i = 0; i < dynamic_objects.size(); i++) {
		dynamic_objects[i].init();
		dynamic_objects[i].update();
		
		if(dynamic_cast<Dog>(dynamic_objects[i])) {
			((Dog) dynamic_objects[i]).bark();
		}
		else if(dynamic_cast<Dragon>(dynamic_objects[i])) {
			((Dragon) dynamic_objects[i]).breath_fire();
		}
		else if(dynamic_cast<Radio>(dynamic_objects[i])) {
			((Radio) dynamic_objects[i]).play_audio();
		}
		else if(dynamic_cast<Door>(dynamic_objects[i])) {
			Door d = (Door) dynamic_objects[i];
			if(d.is_opened()) {
				d.close();
			}
			else {
				d.open();
			}
		}
	}

	return 0;
}
