#include "Fox.h"
#include "Navigation.h"
#include <string>

Fox::Fox(int a, World* w) : Animal(3, 7, a, 'F', w) {}

void Fox::Action() {
	Point newP = Navigation::Translate(location);

	if (world->PointValidate(newP) == false) {
		return;
	}

	Organism* o = world->GetAt(newP);

	if (o != nullptr && this->GetStrength() < o->GetStrength()) {
		return;
	}

	Move(newP);
}

std::string Fox::ToString() {
	return "Fox";
}