#include "Human.h"

Human::Human(int a, World* w) : Animal(5, 4, a, 'H', w) {
	alive = true;
}

void Human::Action() {

}

bool Human::Collision(Organism* o) {
	return true;
}

bool Human::IsAlive() {
	return alive;
}

std::string Human::ToString() {
	return "Player";
}