#include "World.h"
#include "Utilities.h"

#include "conio2.h"
#include "Layout.h"

Board::Board(int r, int c, World* w) {
	row = r;
	col = c;
	world = w;

	organisms = new Organism*[ r*c ];

	for (int i = 0; i < row*col; i++) {
		organisms[i] = nullptr;
	}
}
Board::~Board() {
	delete[] organisms;
}

int Board::GetRow() {
	return row;
}
int Board::GetCol() {
	return col;
}

bool Board::Validate(Point p) {
	if (p.x < 0 || p.y < 0 || p.x >= row || p.y >= col) {
		return false;
	}
	else {
		return true;
	}
}

Point Board::SeekForFree(Point p) {

	seekBuffer.clear();

	int x = (p.x - 1 < 0) ? 0 : p.x - 1;
	int yB = (p.y - 1 < 0) ? 0 : p.y - 1;

	int xMax = (p.x + 1 == row) ? p.x : p.x + 1;
	int yMax = (p.y + 1 == col) ? p.y : p.y + 1;

	Point temp;

	for (; x <= xMax; x++) {
		for (int y = yB; y <= yMax; y++) {
			if (x == p.x && y == p.y) {
				continue;
			}

			temp.x = x;
			temp.y = y;

			if (organisms[GetIndex(temp)] == nullptr) {
				seekBuffer.push_back(temp);
			}
		}
	}

	if (seekBuffer.size() == 0) {
		return NULL_POINT;
	}

	return seekBuffer[Utilities::random(0, seekBuffer.size())];
}
void Board::SetAt(Organism* o) {
	
	seekBuffer.clear();

	Point temp;

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {

			temp.x = x;
			temp.y = y;

			if (organisms[GetIndex(temp)] == nullptr) {
				seekBuffer.push_back(temp);
			}
		}
	}

	if (seekBuffer.size() == 0) {
		return;
	}

	if(!(o->GetLocation() == NULL_POINT)) {
		organisms[GetIndex(o->GetLocation())] = nullptr;
	}

	temp = seekBuffer[Utilities::random(0, seekBuffer.size())];
	o->SetLocation(temp);
	organisms[GetIndex(temp)] = o;
}
Organism* Board::SetAt(Point p, Organism* organism) {

	if (Validate(p) == false) {
		return nullptr;
	}

	Organism* o = GetAt(p);
	if (o == nullptr) {
		if (!(organism->GetLocation() == NULL_POINT)) {
			organisms[GetIndex(organism->GetLocation())] = nullptr;
		}
		organism->SetLocation(p);
		organisms[GetIndex(p)] = organism;
	}
	
	return o;
}
void Board::KillAt(Point p) {
	Organism* o = organisms[GetIndex(p)];

	if (o == nullptr) {
		return;
	}

	organisms[GetIndex(p)] = nullptr;
}
inline Organism* Board::GetAt(Point p) {
	return organisms[GetIndex(p)];
}

void Board::Draw() {

	textbackground(BLACK);
	textcolor(WHITE);

	for (int i = 0; i < row; i++) {

		gotoxy(world->GetLayout()->GetBoardX(), world->GetLayout()->GetBoardY() + i);

		for (int j = 0; j < col; j++) {

			Organism* organism = organisms[i*row + j];

			if (organism == nullptr) {
				putch(' ');
			}
			else {
				organism->Draw();
			}
		}
	}
}

inline int Board::GetIndex(Point p) {
	return p.y * row + p.x;
}