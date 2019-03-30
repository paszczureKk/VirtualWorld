#pragma once

#include <list>
#include "Organism.h"
#include "Board.h"

class World {
	public :
		World();
		World(int rows, int cols, int oc);
		~World();
		
		void NextTurn();
	private:
		int organismsC;

		std::list<Organism*> organisms;
		Board* board;

		void Draw();
};
