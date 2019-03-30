#include "Animal.h"
#include "Utilities.h"
#include "Navigation.h"
#include "World.h"
#include <cstdlib>

Animal::Animal(int s, int i, int a, Point p, World* w) : Organism(s, i, a, p, w) {}

void Animal::Action() {
	Point newP = Navigation::Translate(location);

	if (world->PointValidate(newP) == false) {
		return;
	}

	Organism* o = world->MoveTo(newP, this);

	if (o == nullptr) {
		return;
	}


}
void Animal::Collision() {

}