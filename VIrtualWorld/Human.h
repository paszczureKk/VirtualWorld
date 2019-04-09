#pragma once

#include "Animal.h"
#include <string>
#include "Navigation.h"

class Human : Animal<Human> {
	public:
		Human(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
	private:
		int cooldown;
		int active;

		void CoolDown();
		void ActiveDown();
		void Special();

		bool collisionActive;
		bool actionActive;

		bool(Human::*ActionAbility)();
		bool(Human::*CollisionAbility)(Organism* o);
		bool AlzursShield(Organism* o);

		bool DirCheck(WorldDirections dir);
};