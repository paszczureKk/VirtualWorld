#include "HeracleumSosnowskyi.h"
#include "CyberSheep.h"

HeracleumSosnowskyi::HeracleumSosnowskyi(int a, World* w) : Plant(10, a, 'B', w) {}

void HeracleumSosnowskyi::Action() {
	world->RemoveFromWorld(this->ToString(), location, 
		[](Organism* o) -> bool {
			if (o->IsAnimal() == false) {
				return false;
				}
			if (typeid(o).name() == typeid(CyberSheep).name()) {
				return false;
			}
			return true;
			});

	Plant::Action();
}

bool HeracleumSosnowskyi::Collision(Organism* o) {

	this->Kill(o->ToString());

	if (typeid(o).name() != typeid(CyberSheep).name()) {
		o->Kill(this->ToString());
	}

	return false;
}

std::string HeracleumSosnowskyi::ToString() {
	return "HeracleumSosnowskyi";
}