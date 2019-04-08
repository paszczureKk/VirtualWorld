#pragma once

#include "Animal.h"

class Wolf : Animal<Wolf> {
	public :
		Wolf(int a, World* w);
		std::string ToString() override;
	private :
};