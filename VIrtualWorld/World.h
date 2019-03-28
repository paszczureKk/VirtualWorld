#pragma once

class World {
	public :
		World(int rows, int cols);
		
		void NextTurn();
	private:
		//std::list<Organism*> organisms;
		int organismsC;

		void Draw();
};
