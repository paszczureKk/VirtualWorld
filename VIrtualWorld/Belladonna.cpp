#include "Belladonna.h"

Belladonna::Belladonna(int a, World* w) : Plant(99, a, 'J', w) {}

bool Belladonna::Collision(Organism* o) {
	o->Kill(this->ToString());

	Plant::Collision(o);

	return false;
}

std::string Belladonna::ToString() {
	return "Belladonna";
}