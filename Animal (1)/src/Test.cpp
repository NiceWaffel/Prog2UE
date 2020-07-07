#include "Animal.h"
#include "Dog.h"
#include "Dragon.h"

int main() {
	/* Animal als lokales Objekt */
	Animal a1("Hans", 12);
	a1.init();
	a1.update();

	/* Dynamisch instanziiertes Objekt von Animal */
	Animal *a2 = new Animal("Joerg", 14);
	a2->init();
	a2->update();

	/* Dog als lokales Objekt */
	Dog doggo("Wuffy", 8, "Bernhardiner");
	doggo.init();
	doggo.update();
	doggo.bite(a2);

	/* Drache als lokales Objekt */
	Dragon drago("Drago", 524, 1345);
	drago.init();
	drago.update();
	drago.breath_fire(a2);

	/* Das dynamisch erzeugt Animal wieder löschen */
	delete a2;
}
