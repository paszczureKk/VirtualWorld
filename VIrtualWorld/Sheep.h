#pragma once

#include "Animal.h"
#include <string>

class Sheep : Animal<Sheep> {
	public:
		Sheep(int a, World* w);
		std::string ToString() override;
	private:
};