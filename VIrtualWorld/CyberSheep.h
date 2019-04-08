#pragma once

#include "Animal.h"
#include <string>

class CyberSheep : Animal<CyberSheep> {
	public:
		CyberSheep(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
	private:
};