#pragma once

#include <iostream>

#include <list>
#include "Navigation.h"

#include "Organism.h"
#include "Animal.h"
#include "Plant.h"

#include "Wolf.h"
#include "Turtle.h"
#include "Sheep.h"
#include "Fox.h"
#include "CyberSheep.h"
#include "Antelope.h"

#include "Belladonna.h"
#include "Dandelion.h"
#include "Grass.h"
#include "Guarana.h"
#include "HeracleumSosnowskyi.h"

int main() {
	std::list<Organism*> organisms;

	Point p = Point();
	World* world = new World(10, 10);
	int iterator = 0;

	Belladonna* belladonna = new Belladonna(iterator++, p, *world);
	Dandelion* dandelion = new Dandelion(iterator++, p, *world);
	Grass* grass = new Grass(iterator++, p, *world);
	Guarana* guarana = new Guarana(iterator++, p, *world);
	HeracleumSosnowskyi* heracleumsosnowskyi = new HeracleumSosnowskyi(iterator++, p, *world);

	Antelope* antelope = new Antelope(iterator++, p, *world);
	CyberSheep* cybersheep = new CyberSheep(iterator++, p, *world);
	Fox* fox = new Fox(iterator++, p, *world);
	Sheep* sheep = new Sheep(iterator++, p, *world);
	Turtle* turtle = new Turtle(iterator++, p, *world);
	Wolf* wolf = new Wolf(iterator++, p, *world);

	Organism* o;

	o = (Organism*)belladonna;
	organisms.push_back(o);
	o = (Organism*)dandelion;
	organisms.push_back(o);
	o = (Organism*)grass;
	organisms.push_back(o);
	o = (Organism*)guarana;
	organisms.push_back(o);
	o = (Organism*)heracleumsosnowskyi;
	organisms.push_back(o);

	o = (Organism*)antelope;
	organisms.push_back(o);
	o = (Organism*)cybersheep;
	organisms.push_back(o);
	o = (Organism*)fox;
	organisms.push_back(o);
	o = (Organism*)sheep;
	organisms.push_back(o);
	o = (Organism*)turtle;
	organisms.push_back(o);
	o = (Organism*)wolf;
	organisms.push_back(o);
	

	for (auto it = organisms.begin(); it != organisms.end(); ++it)
		std::cout << ' ' << (*it)->CallI();
	std::cout << std::endl;
	
	organisms.sort(Organism::Compare);

	for (auto it = organisms.begin(); it != organisms.end(); ++it)
		std::cout << ' ' << (*it)->CallI();
	std::cout << std::endl;

	delete world;

	delete belladonna;
	delete dandelion;
	delete grass;
	delete guarana;
	delete heracleumsosnowskyi;

	delete antelope;
	delete cybersheep;
	delete fox;
	delete sheep;
	delete turtle;
	delete wolf;

	system("pause");
}