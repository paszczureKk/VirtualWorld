#pragma once

#include "Animal.h"
#include <string>

class Fox : Animal<Fox> {
	public:
		Fox(int a, World* w);
		void Action() override;
		std::string ToString() override;
	private:
};