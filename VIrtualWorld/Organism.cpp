#include "Organism.h"
#include <iostream>
#include "World.h"

Organism::Organism(int s, int i, int a, Point l) {
	strength = s;
	initiative = i;
	age = a;
	location = l;
}

bool Organism::Compare(Organism* current, Organism* other) {
	if ( current->initiative != other->initiative ) {
		return current->initiative > other->initiative;
	}
	else {
		return current->age > other->age;
	}
}