#include "Grass.h"
#include <string>

Grass::Grass(int a, World* w) : Plant(0, a, 'G', w, 0.07f) {}

std::string Grass::ToString() {
	return "Grass";
}