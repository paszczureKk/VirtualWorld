#pragma once
#include "Organism.h"

class Board {
	public :
		Board(int r, int c);
		~Board();

		void SetAt(Organism* organism);
		Organism* SetAt(Point p, Organism* organism);
	private :
		int row;
		int col;
		Organism** o;

		bool Validate(Point p);
		int GetIndex(Point p);
};