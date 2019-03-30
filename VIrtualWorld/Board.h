#pragma once
#include "Organism.h"

class Board {
	public :
		Board(int r, int c);
		~Board();

		bool Validate(Point p);

		void SetAt(Organism* organism);
		Organism* SetAt(Point p, Organism* organism);

		void Draw();
	private :
		int row;
		int col;
		Organism** o;

		int GetIndex(Point p);
};