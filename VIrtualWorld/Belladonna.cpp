#include "Belladonna.h"
#include <string>

Belladonna::Belladonna(int a, World* w) : Plant(99, a, 'B', w, 0.03f) {}

bool Belladonna::Collision(Organism* o) {
	o->Kill(this->ToString());

	Plant::Collision(o);

	return false;
}

std::string Belladonna::ToString() {
	return "Belladonna";
}