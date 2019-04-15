#pragma once

#include "Animal.h"
#include <string>
#include "Navigation.h"

class Human : public Animal<Human> {
	public:
		Human(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		void Kill(std::string s) override;

		std::string ToString() override;
		std::string GetAbility();

		int GetCooldown();
		int GetDuration();

		bool IsActive();
	private:

		enum Ability {
			ALZURSSHIELD,
			BURNTOFFERING,
			IMMORTALITY,
			ANTELOPESPEED,
			MAGICPOTION,
			ABILITY_COUNT
		};

		int cooldown;
		int active;
		bool immortal;

		void CoolDown();
		void ActiveDown();
		void Special();

		bool collisionActive;
		bool actionActive;
		Ability ability;
		float collisionProb = 0.5f;
		float actionProb = 0.33f;

		bool(Human::*ActionAbility)();
		bool(Human::*CollisionAbility)(Organism* o);
		bool AlzursShield(Organism* o);
		bool Immortality(Organism* o);
		bool MagicPotion();
		bool AntelopeSpeed();
		bool BurntOffering();

		void MakeMove();
		void AbilityRandom();
};