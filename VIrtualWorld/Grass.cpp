#include "Grass.h"

Grass::Grass(int a, World* w) : Plant(0, a, 'T', w) {}

std::string Grass::ToString() {
	return "Grass";
}