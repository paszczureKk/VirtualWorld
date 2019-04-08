#pragma once

#include "Animal.h"
#include <string>

class Antelope : Animal<Antelope> {
	public:
		Antelope(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
	private:

};