#include "World.h"
#include "Navigation.h"

#include "OrganismsHeaders.h"

#include "conio2.h"

World::World(int rows, int cols, int oc) {
	organismsC = 0;

	layout = new Layout;
	LayoutInit(rows, cols);

	board = new Board(rows, cols, this);

	player = new Human(GetAge(), this);
	AddToWorld((Organism*)player);

	Populate(oc);

	DrawOutline(layout->GetBoardX() - 1, layout->GetBoardY() - 1, board->GetRow() + 2, board->GetCol() + 2);
	DrawLegend();
}
World::~World() {
	delete board;
	delete layout;
}

void World::LayoutInit(int r, int c) {

	layout->SetLegendX(layout->GetBoardX() + c + 6);
	layout->SetLegendY(layout->GetBoardY() + 1);

	layout->SetOutputX(layout->GetBoardX());
	layout->SetOutputY(layout->GetBoardY() + r + 6);
}

int World::GetAge() {
	return ++organismsC;
}
Layout* World::GetLayout() {
	return layout;
}

void World::Start() {
	while (player->IsAlive()) {
		NextTurn();
		ClearLegend();
	}
}
void World::Notify(std::string s) {

	gotoxy(layout->GetOutputX(), layout->GetOutputY() + layout->GetOutputHeight());

	textbackground(BLACK);
	textcolor(WHITE);

	Utilities::print(s);

	layout->SetOutputWidth(s.length());
	layout->SetOutputHeight(1);
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

bool World::PointValidate(Point p) {
	return board->Validate(p);
}
Point World::SeekForFree(Point p) {
	return board->SeekForFree(p);
}
Organism* World::GetAt(Point p) {
	return board->GetAt(p);
}
Organism* World::MoveTo(Point p, Organism* o) {
	Point ptemp = o->GetLocation();
	Organism* temp = board->SetAt(p, o);

	return temp;
}

void World::Draw() {
	board->Draw();
}
void World::LegendUpdate(WorldDirections dir, std::string s) {

	ClearLegend();

	textbackground(BLACK);
	textcolor(WHITE);

	std::stringstream temp;

	gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 2);
	Utilities::print("STATISTICS:");
	gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 3);
	temp.str("");
	temp.clear();
	temp << "Strength: " << player->GetStrength();
	Utilities::print(temp.str());
	gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 4);
	temp.str("");
	temp.clear();
	temp << "Position: " << player->GetLocation().ToString();
	Utilities::print(temp.str());

	temp.str("");
	temp.clear();

	gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 6);
	Utilities::print("Next ability");
	gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 7);
	Utilities::print(player->GetAbility());

	if (dir != DIR_NULL) {
		gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 10);
		temp << "Current direction: " << Navigation::ToString(dir);
		gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 11);
		Utilities::print(temp.str());
	}

	if (s.length() != 0) {
		gotoxy(layout->GetLegendX() + 1, layout->GetLegendY() + 13);
		Utilities::print(s);
	}
}
WorldDirections World::GetInput(WorldDirections dir, Point p) {

	int c = 0;
	std::string s = "";


	do {
		LegendUpdate(dir, s);
		c = getch();

		if (c == IS_ARROW_KEY) {
			switch ((c = getch())) {
			case KEY_UP:
				dir = NORTH;
				break;
			case KEY_DOWN:
				dir = SOUTH;
				break;
			case KEY_LEFT:
				dir = WEST;
				break;
			case KEY_RIGHT:
				dir = EAST;
				break;
			default:
				return DIR_NULL;
			}

			if (board->Validate(Navigation::Translate(player->GetLocation(), dir)) == false) {
				s = "Warning. Incorrect direction.";
			}
			else {
				s = "";
			}
		}
		else {
			switch (c) {
			case KEY_ACCEPT:
				return dir;
			case KEY_SPECIAL:
				return DIR_NULL;
			case KEY_SAVE:
				Save();
				break;
			case KEY_LOAD:
				Load();
				Draw();
				LegendUpdate();
				break;
			}
		}
	} while (c != KEY_ACCEPT);

	return DIR_NULL;
	
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

void World::DrawOutline(int x, int y, int height, int width) {

	textbackground(WHITE);

	gotoxy(x, y);
	for (int i = 0; i < width; i++) {
		putch(' ');
	}
	for (int i = 0; i < height - 2; i++) {
		gotoxy(x, y + 1 + i);
		putch(' ');
		gotoxy(x + width - 1, y + 1 + i);
		putch(' ');
	}

	gotoxy(x, y + height - 1);;

	for (int i = 0; i < width; i++) {
		putch(' ');
	}
}
void World::DrawLegend() {
	DrawOutline(layout->GetLegendX() - 1, layout->GetLegendY() - 1, layout->GetLegendHeight() + 2, layout->GetLegendWidth());
	LegendUpdate();
}
void World::ClearLegend() {

	textbackground(BLACK);

	for (int i = 0; i < layout->GetLegendHeight(); i++) {
		gotoxy(layout->GetLegendX(), layout->GetLegendY() + i);

		for (int j = 0; j < layout->GetLegendWidth() - 2; j++) {
			putch(' ');
		}
	}
}
void World::ClearOutput() {

	textbackground(BLACK);

	for (int i = 0; i < layout->GetOutputHeight(); i++) {
		gotoxy(layout->GetOutputX(), layout->GetOutputY() + i);

		for (int j = 0; j < layout->GetOutputWidth(); i++) {
			putch(' ');
		}
	}
}

void World::Save() {

}
void World::Load() {

}