#pragma once

#include "Plant.h"

class Belladonna : Plant<Belladonna> {
	public:
		Belladonna(int a, World* w);
		bool virtual Collision(Organism* o) override;
		std::string ToString() override;
	private:
};