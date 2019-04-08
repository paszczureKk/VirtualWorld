#pragma once

#include "Animal.h"

class Sheep : Animal<Sheep> {
	public:
		Sheep(int a, World* w);
		std::string ToString() override;
	private:
};