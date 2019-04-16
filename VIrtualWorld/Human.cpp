#include "Human.h"
#include "Navigation.h"

#include "Utilities.h"
#include <string>

Human::Human(int a, World* w) : Animal(5, 4, a, 'P', w) {
	cooldown = 0;
	active = 0;

	actionActive = false;
	ActionAbility = nullptr;
}

void Human::Action() {

	world->LegendUpdate();
	world->Draw();

	CoolDown();
	ActiveDown();

	WorldDirections dir = DIR_NULL;
	dir = world->GetInput(dir, location);

	if (dir == DIR_NULL) {
		Special();
	}

	if (ActionAbility != nullptr) {
		if ((this->*ActionAbility)(dir) == false) {
			world->ClearOutput();
			return;
		}
	}

	world->ClearOutput();
	MakeMove(dir);
}
bool Human::Collision(Organism* o) {
	//w tym wypadku zakladam ze czlowiek sie nie rozmnaza (1 gracz na planszy) wiec szkoda czasu na przekazywanie dalej sterowania xD

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
		if (active == 0) {
			actionActive = false;
			ActionAbility = nullptr;
			cooldown = 5;
		}
	}
}

void Human::Special() {
	if (cooldown > 0 || active > 0) {
		return;
	}

	active = 5;

	actionActive = true;
	ActionAbility = &Human::AntelopeSpeed;
}

bool Human::AntelopeSpeed(WorldDirections dir) {

	for (int i = 0; i < 2; i++) {
		if (this->IsAlive()) {
			world->Draw();
			world->LegendUpdate();

			MakeMove(dir);
			dir = DIR_NULL;
		}
	}

	return false;
}

int Human::GetCooldown() {
	return cooldown;
}
int Human::GetDuration() {
	return active;
}

void Human::MakeMove(WorldDirections dir) {
	   
	while (dir == DIR_NULL) {
		dir = world->GetInput(dir, location);

	} 

	Move(Navigation::Translate(location, dir));
}

bool Human::IsActive() {

	if (actionActive == true) {
		return true;
	}
	else {
		return false;
	}
}

std::string Human::GetAbility() {
	return "Antelope Speed";
}