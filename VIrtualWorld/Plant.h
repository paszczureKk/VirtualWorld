#pragma once

#include "Organism.h"

class Plant : Organism {
	public:
		Plant(int s, int a, Point p, World* w);

		void virtual Action() override;
	private:
};