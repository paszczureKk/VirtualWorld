#pragma once

#include "Plant.h"
#include <string>

class Dandelion : Plant<Dandelion> {
	public:
		Dandelion(int a, World* w);
		void virtual Action() override;
		std::string ToString() override;
	private:
};