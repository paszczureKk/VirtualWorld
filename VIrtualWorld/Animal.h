#pragma once

#include "Organism.h"

class Animal : Organism {
	public :
		Animal(int s, int i, int a, Point p, World& w);

		void Action() override;
		void Collision() override;
		void Draw() override;
	private :
};