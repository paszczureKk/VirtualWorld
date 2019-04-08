#pragma once

#include "Animal.h"
#include <string>

class Human : Animal<Human> {
	public:
		Human(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
	private:
};