#pragma once

#include <iostream>

#include "World.h"
#include "OrganismsHeaders.h"
#include "Utilities.h"

int main() {
	Utilities::init();
	
	World* world = new World(10, 10);

	world->Start();

	delete world;

	system("pause");
}