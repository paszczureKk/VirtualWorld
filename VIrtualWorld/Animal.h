#pragma once

#include "Organism.h"

class Animal : Organism {
	public :
		Animal(int s, int i, int a, Point p);

		void Action() override;
		void Collision() override;
	private :
};