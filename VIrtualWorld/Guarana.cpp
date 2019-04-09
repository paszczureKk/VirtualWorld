#include "Guarana.h"
#include <string>

Guarana::Guarana(int a, World* w) : Plant(0, a, 'U', w, 0.07f) {}

bool Guarana::Collision(Organism* o) {
	o->Buff(3);

	Plant::Collision(o);

	return false;
}

std::string Guarana::ToString() {
	return "Guarana";
}