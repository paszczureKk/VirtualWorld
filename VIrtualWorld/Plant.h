#pragma once

#include "Organism.h"

class Plant : Organism {
	public:
		Plant(int s, int a, Point p);

		void Action() override;
	private:
};