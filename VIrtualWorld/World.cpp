#include "World.h"
#include "Board.h"
#include "Organism.h"

World::World() {}
World::World(int rows, int cols, int oc) {
	organismsC = 0;

	board = new Board(rows, cols);

	for (int i = 0; i < oc; i++) {
	}
}
World::~World() {
	delete board;
}

void World::NextTurn() {
	organisms.sort(Organism::Compare);

	for (Organism* o : organisms) {
		o->Action();
	}
}

void World::Draw() {
	board->Draw();
}
