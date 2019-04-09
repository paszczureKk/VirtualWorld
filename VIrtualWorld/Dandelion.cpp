#include "Dandelion.h"
#include <string>

Dandelion::Dandelion(int a, World* w) : Plant(0, a, 'D', w, 0.05f) {}

void Dandelion::Action() {
	for (int i = 0; i < 3; i++) {
		Plant::Action();
	}
}

std::string Dandelion::ToString() {
	return "Dandelion";
}