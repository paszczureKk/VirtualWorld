#include "Sheep.h"

Sheep::Sheep(int a, World* w) : Animal(4, 4, a, 'S', w) {}

std::string Sheep::ToString() {
	return "Sheep";
}