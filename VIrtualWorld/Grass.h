#pragma once

#include "Plant.h"
#include <string>

class Grass : Plant<Grass> {
	public:
		Grass(int a, World* w);
		std::string ToString() override;
	private:
};