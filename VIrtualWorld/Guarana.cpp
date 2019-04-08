#include "Guarana.h"

Guarana::Guarana(int a, World* w) : Plant(0, a, 'G', w) {}

bool Guarana::Collision(Organism* o) {
	o->Buff(3);

	Plant::Collision(o);

	return false;
}

std::string Guarana::ToString() {
	return "Guarana";
}