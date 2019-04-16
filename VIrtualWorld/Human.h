#pragma once

#include "Animal.h"
#include <string>
#include "Navigation.h"

class Human : public Animal<Human> {
	public:
		Human(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;

		std::string ToString() override;

		int GetCooldown();
		int GetDuration();

		bool IsActive();
		
		std::string GetAbility();
	private:
		
		int cooldown;
		int active;

		void CoolDown();
		void ActiveDown();
		void Special();

		bool actionActive;

		bool(Human::*ActionAbility)(WorldDirections dir);
		bool AntelopeSpeed(WorldDirections dir);

		void MakeMove(WorldDirections dir);
};