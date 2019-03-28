#include "Organism.h"
#include <iostream>

Organism::Organism(int s, int i, int a, Point l, World& w) {
	strength = s;
	initiative = i;
	age = a;
	location = l;
	world = &w;
}

int Organism::CallI() {
	return initiative;
}

bool Organism::Compare(Organism* current, Organism* other) {
	if ( current->initiative != other->initiative ) {
		return current->initiative > other->initiative;
	}
	else {
		return current->age > other->age;
	}
}