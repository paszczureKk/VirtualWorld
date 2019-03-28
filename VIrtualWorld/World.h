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
		std::list<Organism*> organisms;
		int organismsC;
		Board* board;

		void Draw();
};
