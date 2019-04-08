#include "Dandelion.h"
#include <string>

Dandelion::Dandelion(int a, World* w) : Plant(0, a, 'M', w) {}

void Dandelion::Action() {
	for (int i = 0; i < 3; i++) {
		Plant::Action();
	}
}

std::string Dandelion::ToString() {
	return "Dandelion";
}