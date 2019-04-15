#include "World.h"
#include "Navigation.h"

#include "OrganismsHeaders.h"
#include "Utilities.h"

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
void World::SetAge(int value) {
	organismsC = value;
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
				ClearOutput();
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
Organism* World::Create(std::string s, int a) {

	Organism* o = nullptr;

	switch (Utilities::str2int(s.c_str())) {
		case Utilities::str2int("Antelope"):
			o = (Organism*) new Antelope(a, this);
		case Utilities::str2int("CyberSheep"):
		case Utilities::str2int("Fox"):
		case Utilities::str2int("Sheep"):
		case Utilities::str2int("Turtle"):
		case Utilities::str2int("Wolf"):

		case Utilities::str2int("Belladonna"):
		case Utilities::str2int("Dandelion"):
		case Utilities::str2int("Grass"):
		case Utilities::str2int("Guarana"):
		case Utilities::str2int("HeracleumSosnowskyi"):

		case Utilities::str2int("Player"):
	}

	return o;
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

	FILE* file = fopen("save.txt", "w");

	//saving

	//	layout
	//board
	fprintf(file, "%d,%d\n", layout->GetBoardX(), layout->GetBoardY());
	//output
	fprintf(file, "%d,%d,%d,%d\n", layout->GetOutputX(), layout->GetOutputY(), layout->GetOutputWidth(), layout->GetOutputHeight());
	//legend
	fprintf(file, "%d,%d,%d,%d\n", layout->GetLegendX(), layout->GetLegendY(), layout->GetLegendWidth(), layout->GetLegendHeight());

	//world
	fprintf(file, "%d\n", organismsC);

	//board
	fprintf(file, "%d,%d", board->GetRow(), board->GetCol());

	//organisms
	for (int y = 0; y < board->GetRow(); y++)
	{
		for (int x = 0; x < board->GetCol(); x++) {
			Organism* o = GetAt({ x, y });

			if (o == nullptr) {
				fprintf(file, "%d\n", 0);
			}
			else {
				fprintf(file, "%d,%s,%d,%d,%d,%d", 1, o->ToString(), o->GetAge(), o->GetStrength(), o->GetLocation().x, o->GetLocation().y);
			}
		}
	}

	//born
	fprintf(file, "%d\n", born.size());
	for (Organism* o : born) {
		if (o == nullptr) {
			fprintf(file, "%d\n", 0);
		}
		else {
			fprintf(file, "%d,%s,%d,%d,%d", 1, o->ToString(), o->GetAge(), o->GetStrength(), o->GetLocation().x, o->GetLocation().y);
		}
	}
	//dead
	fprintf(file, "%d\n", dead.size());
	for (Organism* o : dead) {
		if (o == nullptr) {
			fprintf(file, "%d\n", 0);
		}
		else {
			fprintf(file, "%d,%s,%d,%d,%d", 1, o->ToString(), o->GetAge(), o->GetStrength(), o->GetLocation().x, o->GetLocation().y);
		}
	}

	fclose(file);
	Notify("Saving complete!");
}
void World::Load() {
	FILE* file = fopen("save.txt", "r");

	if (file == NULL) {
		return;
	}

	int a1, a2, a3, a4;

	//layout
	//board
	fscanf(file, "%d,%d", &a1, &a2);
	layout->SetBoardX(a1);
	layout->SetBoardY(a2);
	//output
	fscanf(file, "%d,%d,%d,%d", &a1, &a2, &a3, &a4);
	layout->SetOutputX(a1);
	layout->SetOutputY(a2);
	layout->SetOutputWidth(a3);
	layout->SetOutputHeight(a4);
	//legend
	fscanf(file, "%d,%d,%d,%d", &a1, &a2, &a3, &a4);
	layout->SetLegendX(a1);
	layout->SetLegendY(a2);
	layout->SetLegendWidth(a3);
	layout->SetLegendHeigth(a4);

	//world
	fscanf(file, "%d", &a1);
	this->SetAge(a1);

	fscanf(file, "%d,%d", &a1, &a2);

	delete board;
	board = new Board(a1, a2, this);

	int b1, b2, b3, b4, b5;
	std::string s;

	//organisms
	for (int i = 0; i < a1*a2; i++) {
		fscanf(file, "%d", &b1);

		if (b1 == 0) {
			continue;
		}

		fscanf(file, "%s,%d,%d,%d,%d", s, &b2, &b3, &b4, &b5);

		Organism* o = Create(s, b2);
		o->SetStrength(b3);
		o->SetLocation({ b4,b5 });
		AddToWorld(o, o->GetLocation());
	}

	//born
	fscanf(file, "%d\n", &a1);
	for (Organism* o : born) {
		delete o;
	}
	born.clear();
	for (int i = 0; i < a1; i++) {
		fscanf(file, "%d", &b1);

		if (b1 == 0) {
			continue;
		}

		fscanf(file, "%s,%d,%d,%d,%d", s, &b2, &b3, &b4, &b5);

		Organism* o = Create(s, b2);
		o->SetStrength(b3);
		o->SetLocation({ b4,b5 });
		born.push_back(o);
	}

	//dead
	fscanf(file, "%d\n", &a1);
	for (Organism* o : dead) {
		delete o;
	}
	born.clear();
	for (int i = 0; i < a1; i++) {
		fscanf(file, "%d", &b1);

		if (b1 == 0) {
			continue;
		}

		fscanf(file, "%s,%d,%d,%d,%d", s, &b2, &b3, &b4, &b5);

		Organism* o = Create(s, b2);
		o->SetStrength(b3);
		o->SetLocation({ b4,b5 });
		dead.push_back(o);
	}

	fclose(file);
	Notify("Loading complete!");
}