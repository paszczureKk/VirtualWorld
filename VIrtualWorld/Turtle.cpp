#include "Turtle.h"
#include "Utilities.h"
#include <string>

Turtle::Turtle(int a, World* w) : Animal(2, 1, a, 'T', w) {}

void Turtle::Action() {
	if (0.25f < Utilities::random(0.0f, 1.0f)) {
		return;
	}

	Animal::Action();
}

bool Turtle::Collision(Organism* o) {
	if (TypeCheck(o) == false) {
		if (o->GetStrength() < 5) {
			return false;
		}
	}

	return Animal::Collision(o);
}

std::string Turtle::ToString() {
	return "Turtle";
}