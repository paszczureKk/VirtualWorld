#pragma once

#include <iostream>

#include "World.h"
#include "OrganismsHeaders.h"
#include "Utilities.h"

int main() {

	Utilities::init();
	
	World* world = new World(20, 20);

	world->Start();

	delete world;

	system("pause");
}