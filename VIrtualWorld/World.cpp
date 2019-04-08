#include "World.h"
#include "Navigation.h"

#include "OrganismsHeaders.h"

#include <Windows.h>
#include <iostream>

World::World(int rows, int cols, int oc) {
	organismsC = 0;

	board = new Board(rows, cols);

	player = new Human(GetAge(), this);
	AddToWorld((Organism*)player);

	Populate(oc);
}
World::~World() {
	delete board;
}

void World::AddToWorld(Organism* o) {
	born.push_back(o);

	if (o->GetLocation() == NULL_POINT) {
		board->SetAt(o);
	}
	else {
		board->SetAt(o->GetLocation(), o);
	}
}
void World::RemoveFromWorld(Organism* o) {
	dead.push_back(o);
}
void World::RemoveFromWorld(std::string s, Point p, bool(*ToKill)(Organism* o)) {
	int x = (p.x - 1 < 0) ? 0 : p.x - 1;
	int y = (p.y - 1 < 0) ? 0 : p.y - 1;

	int xMax = (p.x + 1 == board->GetRow()) ? p.x : p.x + 1;
	int yMax = (p.y + 1 == board->GetCol()) ? p.y : p.y + 1;

	Point temp;

	for (; x <= xMax; x++) {
		for (; y <= yMax; y++) {
			if (x == y) {
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

//TO DO HUMAN TURN
void World::NextTurn() {
	if (born.size() != 0) {
		for (Organism* o : born) {
			organisms.push_back(o);
		}

		born.clear();
		organisms.sort(Organism::Compare);
	}

	Draw();
	std::cout << std::endl;

	for (Organism* o : organisms) {
		o->Action();

		if (dead.size() != 0) {
			for (Organism* o : dead) {
				board->KillAt(o->GetLocation());
			}
			dead.clear();
		}
	}

	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
}

void World::Populate(int n = 2) {

	for (int i = 0; i < n; i++) {

		Organism* o;

		o = ((Organism*)new Antelope(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new CyberSheep(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new Fox(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new Sheep(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new Turtle(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new Wolf(GetAge(), this));
		AddToWorld(o);

		o = ((Organism*)new Belladonna(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new Dandelion(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new Grass(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new Guarana(GetAge(), this));
		AddToWorld(o);
		o = ((Organism*)new HeracleumSosnowskyi(GetAge(), this));
		AddToWorld(o);

		/*AddToWorld((Organism*)new Antelope(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new CyberSheep(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new Fox(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new Sheep(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new Turtle(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new Wolf(GetAge(), NULL_POINT, this));

		AddToWorld((Organism*)new Belladonna(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new Dandelion(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new Grass(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new Guarana(GetAge(), NULL_POINT, this));
		AddToWorld((Organism*)new HeracleumSosnowskyi(GetAge(), NULL_POINT, this));*/
	}
}

void World::Draw() {
	board->Draw();
}

void World::GetInput() {

}

void World::Start() {
	/*while (player->IsAlive()) {
		GetInput();
		NextTurn();
	}*/
	
	for (int i = 0; i < 20; i++) {
		NextTurn();
	}
}
//TO DO
void World::Notify(std::string s) {
	printf_s("%s", s);
}