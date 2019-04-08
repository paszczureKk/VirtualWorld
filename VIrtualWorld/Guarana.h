#pragma once

#include "Plant.h"

class Guarana : Plant<Guarana> {
	public:
		Guarana(int a, World* w);
		bool virtual Collision(Organism* o) override;
		std::string ToString() override;
	private:
};