#include "Human.h"
#include <string>

Human::Human(int a, World* w) : Animal(5, 4, a, 'H', w) {}

void Human::Action() {

}

bool Human::Collision(Organism* o) {
	return true;
}

std::string Human::ToString() {
	return "Player";
}