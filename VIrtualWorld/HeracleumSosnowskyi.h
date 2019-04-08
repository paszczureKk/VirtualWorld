#pragma once

#include "Plant.h"
#include <string>

class HeracleumSosnowskyi : Plant<HeracleumSosnowskyi> {
	public:
		HeracleumSosnowskyi(int a, World* w);
		void Action() override;
		bool Collision(Organism* o) override;
		std::string ToString() override;
	private:
};