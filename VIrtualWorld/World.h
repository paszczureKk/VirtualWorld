#pragma once

#include <list>
class Organism;
class Board;

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
