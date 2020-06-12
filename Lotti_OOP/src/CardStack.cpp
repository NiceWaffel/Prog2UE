#include "CardStack.h"

CardStack::CardStack() {
	srand(time(NULL));
}

int CardStack::draw() {
	return rand() % 4;
}
