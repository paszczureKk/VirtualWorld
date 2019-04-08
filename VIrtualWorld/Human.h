#pragma once

#include "Animal.h"

class Human : Animal<Human> {
	public:
		Human(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
		bool IsAlive();
	private:
		bool alive;
};