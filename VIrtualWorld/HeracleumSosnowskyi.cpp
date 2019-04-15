#include "HeracleumSosnowskyi.h"
#include "CyberSheep.h"
#include <string>

HeracleumSosnowskyi::HeracleumSosnowskyi(int a, World* w) : Plant(10, a, 'H', w, 0.01f) {}

void HeracleumSosnowskyi::Action() {
	world->RemoveFromWorld(this->ToString(), location, 
		[](Organism* o) -> bool {
			if (o->IsAnimal() == false) {
				return false;
				}
			if (o->ToString() == "CyberSheep") {
				return false;
			}
			return true;
			});

	Plant::Action();
}

bool HeracleumSosnowskyi::Collision(Organism* o) {

	this->Kill(o->ToString());

	if (o->ToString() != "CyberSheep") {
		o->Kill(this->ToString());
	}

	return false;
}

std::string HeracleumSosnowskyi::ToString() {
	return "HeracleumSosnowskyi";
}