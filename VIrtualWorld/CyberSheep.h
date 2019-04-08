#pragma once

#include "Animal.h"

class CyberSheep : Animal<CyberSheep> {
	public:
		CyberSheep(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
	private:
};