#include "Antelope.h"
#include "Utilities.h"

Antelope::Antelope(int a, World* w) : Animal(4, 4, a, 'A', w) {}

void Antelope::Action() {
	for (int i = 0; i < 2; i++) {
		Animal::Action();
	}
}
bool Antelope::Collision(Organism* o) {

	if (0.5f < Utilities::random(0.0f, 1.0f)) {
		Point newP = Navigation::Translate(location);

		Point p = location;
		Move(newP);

		o->Move(p);

		return false;
	}

	return Animal::Collision(o);
}

std::string Antelope::ToString() {
	return "Antelope";
}