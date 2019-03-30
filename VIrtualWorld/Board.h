#pragma once
#include "Navigation.h"
class Organism;

class Board {
	public :
		Board(int r, int c);
		~Board();

		bool Validate(Point p);

		void SetAt(Organism* organism);
		Organism* SetAt(Point p, Organism* organism);
		Organism* GetAt(Point p);

		void Draw();
	private :
		int row;
		int col;
		Organism** organisms;

		int GetIndex(Point p);
};