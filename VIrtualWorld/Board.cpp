#include "Board.h"
#include "Utilities.h"
#include "Organism.h"
#include <iostream>

Board::Board(int r, int c) {
	row = r;
	col = c;

	organisms = new Organism*[ r*c ];

	for (int i = 0; i < row*col; i++) {
		organisms[i] = nullptr;
	}
}
Board::~Board() {
	delete[] organisms;
}

bool Board::Validate(Point p) {
	if (p.x < 0 || p.y < 0 || p.x >= row || p.y >= col) {
		return false;
	}
	else {
		return true;
	}
}
inline int Board::GetIndex(Point p) {
	return p.y * row + p.x;
}

inline Organism* Board::GetAt(Point p) {
	return organisms[GetIndex(p)];
}

void Board::SetAt(Organism* organism) {
	int max = row * col;

	int random;

	while (organisms[(random = Utilities::random(0, max))] != nullptr) {
		;
	}

	organisms[random] = organism;
}
Organism* Board::SetAt(Point p, Organism* organism) {
	if (Validate(p) == false) {
		return nullptr;
	}

	Organism* o = GetAt(p);
	if (o == nullptr) {
		organisms[GetIndex(p)] = organism;
	}
	
	return o;
}

void Board::Draw() {
	for (int i = 0; i < row*col; i++) {

		if (i % row == 0)
			std::cout << std::endl;

		Organism* organism = organisms[i];

		if (organism == nullptr) {
			std::cout << " ";
		}
		else {
			organism->Draw();
		}
	}
}