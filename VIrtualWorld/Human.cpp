#include "Human.h"
#include "Navigation.h"

#include "Utilities.h"
#include <string>

Human::Human(int a, World* w) : Animal(5, 4, a, 'P', w) {
	cooldown = 0;
	active = 0;

	collisionActive = false;
	actionActive = false;

	CollisionAbility = nullptr;
	ActionAbility = nullptr;

	AbilityRandom();
}

void Human::Action() {

	world->LegendUpdate();

	CoolDown();
	ActiveDown();

	world->Draw();

	if (ActionAbility != nullptr) {
		if ((this->*ActionAbility)() == false) {
			world->LegendUpdate();
			return;
		}
	}

	MakeMove();

	world->LegendUpdate();
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

	switch (ability) {
		case ALZURSSHIELD:
			collisionActive = true;
			CollisionAbility = &Human::AlzursShield;
			break;
		case IMMORTALITY:
			collisionActive = true;
			CollisionAbility = &Human::Immortality;
			break;
		case BURNTOFFERING:
			actionActive = true;
			ActionAbility = &Human::BurntOffering;
			break;
		case ANTELOPESPEED:
			actionActive = true;
			ActionAbility = &Human::AntelopeSpeed;
			break;
		case MAGICPOTION:
			actionActive = true;
			ActionAbility = &Human::MagicPotion;
			break;
		default:
			break;
	}
}

bool Human::AlzursShield(Organism* o) {

	o->Move(Navigation::Translate(location));

	return false;
}

bool Human::Immortality(Organism* o) {
	Point p = this->location;

	this->Move(Navigation::Translate(location));
	o->Move(p);

	return false;
}
bool Human::MagicPotion() {
	this->Buff(-2);
	return true;
}
bool Human::AntelopeSpeed() {
	for (int i = 0; i < 2; i++) {
		if (this->IsAlive()) {
			MakeMove();
		}
	}

	return false;
}
bool Human::BurntOffering() {
	world->RemoveFromWorld(this->ToString(), location,
		[](Organism* o) -> bool {
		if (o == nullptr) {
			return false;
		}

		return true;
	});

	return true;
}

std::string Human::GetAbility() {
	switch (ability) {
		case ALZURSSHIELD:
			return "Alzur\'s Shield";
		case BURNTOFFERING:
			return "Burnt Offering";
		case IMMORTALITY:
			return "Immortality";
		case ANTELOPESPEED:
			return "Antelope Speed";
		case MAGICPOTION:
			return "Magic Potion";
		default:
			return NULL;
	}
}

void Human::MakeMove() {

	WorldDirections dir = DIR_NULL;

	dir = world->GetInput(dir, location);

	if (dir == DIR_NULL) {
		Special();
	}

	if (ActionAbility != nullptr) {
		if ((this->*ActionAbility)() == false) {
			return;
		}
	}

	Move(Navigation::Translate(location, dir));
}

void Human::AbilityRandom() {
	float prob = 1.0f / ABILITY_COUNT;

	float r = Utilities::random(0.0f, 1.0f);
	int a = (int)(r / prob);

	ability = (Ability)a;
}