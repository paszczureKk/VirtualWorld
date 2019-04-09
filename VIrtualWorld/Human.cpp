#include "Human.h"
#include "Navigation.h"

#include <string>

Human::Human(int a, World* w) : Animal(5, 4, a, 'P', w) {
	cooldown = 0;
	active = 0;

	collisionActive = false;
	actionActive = false;

	CollisionAbility = nullptr;
	ActionAbility = nullptr;
}

void Human::Action() {

	CoolDown();
	ActiveDown();

	world->Draw();
	WorldDirections dir = DIR_NULL;

	do {
		dir = world->GetInput(dir, location);

		if (dir == DIR_NULL) {
			Special();
		}

	} while (DirCheck(dir) == false);

	if (ActionAbility != nullptr) {
		if ((this->*ActionAbility)() == false) {
			return;
		}
	}

	Move(Navigation::Translate(location, dir));
}

bool Human::Collision(Organism* o) {
	if (CollisionAbility != nullptr) {
		if ((this->*CollisionAbility)(o) == false) {
			return false;
		}
	}

	return true;
}

std::string Human::ToString() {
	return "Player";
}

void Human::CoolDown() {
	if (cooldown > 0) {
		cooldown--;
	}
}
void Human::ActiveDown() {
	if (active > 0) {
		active--;
	}
	else {
		collisionActive = false;
		actionActive = false;
		CollisionAbility = nullptr;
		ActionAbility = nullptr;
		cooldown = 5;
	}
}

void Human::Special() {
	if (cooldown > 0) {
		return;
	}

	active = 5;

	collisionActive = true;
	CollisionAbility = &Human::AlzursShield;
}

bool Human::DirCheck(WorldDirections dir) {
	return ( ((int)dir < (int)DIRECTIONS_COUNT) ? true : false);
}

bool Human::AlzursShield(Organism* o) {

	o->Move(Navigation::Translate(location));

	return false;
}