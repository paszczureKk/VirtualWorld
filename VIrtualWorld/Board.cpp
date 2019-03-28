#include "Board.h"
#include <cstdlib>

Board::Board(int r, int c) {
	row = r;
	col = c;

	o = new Organism*[ r*c ];

	for (int i = 0; i < row*col; i++) {
		o[i] = nullptr;
	}
}
Board::~Board() {
	delete[] o;
}

bool Board::Validate(Point p) {
	if (p.x < 0 || p.y < 0 || p.x >= row || p.y >= col) {
		return false;
	}
	else {
		return true;
	}
}
int Board::GetIndex(Point p) {
	return p.y * row + p.x;
}

void Board::SetAt(Organism* organism) {
	int max = row * col;

	int random;

	while (o[(random = rand() % max)] != nullptr) {
		;
	}

	o[random] = organism;
}
Organism* Board::SetAt(Point p, Organism* organism) {
	if (Validate(p) == false) {
		return nullptr;
	}

	int index = GetIndex(p);
	if (o[index] == nullptr) {
		o[index] = organism;
		return nullptr;
	}
	else {
		return o[index];
	}
}