#pragma once

#include "Animal.h"

class Turtle : Animal<Turtle> {
	public:
		Turtle(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
	private:
};