#include "World.h"
#include "Navigation.h"

#include "OrganismsHeaders.h"

#include "conio2.h"

World::World(int rows, int cols, int oc) {
	organismsC = 0;

	layout = new Layout;
	LayoutInit(rows, cols);

	board = new Board(rows, cols, this);

	player = (Organism*)new Human(GetAge(), this);
	AddToWorld(player);

	Populate(oc);
}
World::~World() {
	delete board;
	delete layout;
}

void World::AddToWorld(Organism* o, Point p) {
	born.push_back(o);

	if (p == NULL_POINT) {
		board->SetAt(o);
	}
	else {
		board->SetAt(p, o);
	}
}
void World::RemoveFromWorld(Organism* o) {
	board->KillAt(o->GetLocation());
	dead.push_back(o);
}
void World::RemoveFromWorld(std::string s, Point p, bool(*ToKill)(Organism* o)) {
	int x = (p.x - 1 < 0) ? 0 : p.x - 1;
	int yB = (p.y - 1 < 0) ? 0 : p.y - 1;

	int xMax = (p.x + 1 == board->GetRow()) ? p.x : p.x + 1;
	int yMax = (p.y + 1 == board->GetCol()) ? p.y : p.y + 1;

	Point temp;

	for (; x <= xMax; x++) {
		for (int y = yB; y <= yMax; y++) {
			if (x == p.x && y == p.y) {
				continue;
			}

			temp.x = x;
			temp.y = y;

			Organism* o = board->GetAt(temp);
			if (o == nullptr) {
				continue;
			}
			if (ToKill(o) == false) {
				continue;
			}

			o->Kill(s);
		}
	}
}

int World::GetAge() {
	return ++organismsC;
}
Point World::SeekForFree(Point p) {
	return board->SeekForFree(p);
}

bool World::PointValidate(Point p) {
	return board->Validate(p);
}

Organism* World::GetAt(Point p) {
	return board->GetAt(p);
}
Organism* World::MoveTo(Point p, Organism* o) {
	Point ptemp = o->GetLocation();
	Organism* temp = board->SetAt(p, o);

	return temp;
}

void World::NextTurn() {

	if (born.size() != 0) {
		for (Organism* o : born) {
			organisms.push_back(o);
		}

		born.clear();
		organisms.sort(Organism::Compare);
	}

	for (Organism* o : organisms) {
		if (o->IsAlive() == true) {
			o->Action();
		}
	}

	if (dead.size() != 0) {
		for (Organism* o : dead) {
			organisms.remove(o);
		}
		dead.clear();
	}
}

void World::Populate(int n = 2) {

	for (int i = 0; i < n; i++) {

		AddToWorld((Organism*)new Antelope(GetAge(), this));
		AddToWorld((Organism*)new CyberSheep(GetAge(), this));
		AddToWorld((Organism*)new Fox(GetAge(), this));
		AddToWorld((Organism*)new Sheep(GetAge(), this));
		AddToWorld((Organism*)new Turtle(GetAge(), this));
		AddToWorld((Organism*)new Wolf(GetAge(), this));

		AddToWorld((Organism*)new Belladonna(GetAge(), this));
		AddToWorld((Organism*)new Dandelion(GetAge(), this));
		AddToWorld((Organism*)new Grass(GetAge(), this));
		AddToWorld((Organism*)new Guarana(GetAge(), this));
		AddToWorld((Organism*)new HeracleumSosnowskyi(GetAge(), this));
	}
}

void World::Draw() {
	board->Draw();
}

//TO DO
WorldDirections World::GetInput(WorldDirections direction, Point p) {
	int c = 0;
	WorldDirections dir;

	switch ((c = getch())) {
	case KEY_UP:
		dir = NORTH;
	case KEY_DOWN:
		dir = SOUTH;
	case KEY_LEFT:
		dir = EAST;
	case KEY_RIGHT:
		dir = WEST;
	case KEY_ACCEPT:
		return dir;
	case KEY_SPECIAL:
	default:
		return DIR_NULL;
	}
}

void World::Start() {
	while (player->IsAlive()) {
		NextTurn();
		ClearLegend();
	}
}

void World::Notify(std::string s) {
	
	gotoxy(layout->GetOutputX(), layout->GetOutputY() + layout->GetOutputHeight());

	textbackground(BLUE);
	textcolor(BLACK);

	for (int i = 0; s[i] != '\0'; i++) {
		putch(s[i]);
	}

	layout->SetOutputWidth(s.length());
	layout->SetOutputHeight(1);
}

void World::LayoutInit(int r, int c) {

	layout->SetLegendX(layout->GetBoardX() + c + 6);
	layout->SetLegendX(layout->GetBoardY() + 1);

	layout->SetOutputX(layout->GetBoardX());
	layout->SetOutputY(layout->GetBoardY() + r + 6);
}

void World::ClearLegend() {

	textbackground(BLACK);

	for (int i = 0; i < layout->GetOutputHeight(); i++) {
		gotoxy(layout->GetLegendX(), layout->GetLegendY() + i);

		for (int j = 0; j < layout->GetOutputWidth(); i++) {
			putch(' ');
		}
	}

}

Layout* World::GetLayout() {
	return layout;
}