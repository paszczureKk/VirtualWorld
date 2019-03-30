#pragma once

#include "Organism.h"

class Animal : Organism {
	public :
		Animal(int s, int i, int a, Point p, World* w);

		void virtual Action() override;
		void virtual Collision() override;
	private :
};