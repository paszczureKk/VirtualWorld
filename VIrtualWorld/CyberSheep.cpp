#include "CyberSheep.h"
#include "HeracleumSosnowskyi.h"
#include <string>

CyberSheep::CyberSheep(int a, World* w) : Animal(11, 4, a, 'C', w) {}

//TO DO
void CyberSheep::Action() {
	Animal::Action();
}

bool CyberSheep::Collision(Organism* o) {
	if (o->ToString() == "HeracleumSosnowskyi") {
		o->Kill(this->ToString());
		return false;
	}

	return Animal::Collision(o);
}

std::string CyberSheep::ToString() {
	return "CyberSheep";
}