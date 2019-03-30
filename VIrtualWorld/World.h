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
		bool PointValidate(Point p);
		Organism* MoveTo(Point p, Organism* o);
	private:
		int organismsC;

		std::list<Organism*> organisms;
		Board* board;

		void Draw();
};
