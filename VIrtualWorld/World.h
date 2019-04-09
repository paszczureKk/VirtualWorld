#pragma once

#include <list>
#include <vector>
#include "Navigation.h"
#include "Layout.h"

class Board;
class Organism;

class World {
	public :
		World(int rows, int cols, int oc = 2);
		~World();

		void LayoutInit(int r, int c);

		int GetAge();

		void Start();
		void Notify(std::string s);

		void AddToWorld(Organism* o, Point p = NULL_POINT);
		void RemoveFromWorld(Organism* o);
		void RemoveFromWorld(std::string s, Point p, bool(*ToKill)(Organism* o));
		
		bool PointValidate(Point p);
		Point SeekForFree(Point p);
		Organism* GetAt(Point p);
		Organism* MoveTo(Point p, Organism* o);

		WorldDirections GetInput(WorldDirections direction, Point p);
		void Draw();

		Layout* GetLayout();

	private:

		int organismsC;
		Organism* player;

		std::list<Organism*> organisms;
		std::list<Organism*> born;
		std::list<Organism*> dead;
		Board* board;

		Layout* layout;

		void Populate(int n);

		void NextTurn();

		void ClearLegend();
};

class Organism {
public:
	Organism(int s, int i, int a, char ch, World* w);

	virtual void Action() = 0;
	virtual bool Collision(Organism* o) = 0;
	virtual void Draw();
	virtual void Move(Point p) = 0;
	virtual std::string ToString() = 0;

	virtual void Kill(std::string s);
	void Buff(int value);

	Point GetLocation();
	void SetLocation(Point p);
	int GetStrength();
	virtual bool IsAnimal() = 0;
	bool IsAlive();

	static bool Compare(Organism* current, Organism* other);
protected:
	int strength;
	int initiative;
	int age;
	Point location;
	World* world;
	char image;
	bool alive;

	void Fight(Organism* o);
private:
};

class Board {
public:
	Board(int r, int c, World* w);
	~Board();

	int GetRow();
	int GetCol();

	bool Validate(Point p);

	Point SeekForFree(Point p);
	void SetAt(Organism* o);
	Organism* SetAt(Point p, Organism* organism);
	void KillAt(Point p);
	Organism* GetAt(Point p);

	void Draw();
	void DrawOutline();
private:
	int row;
	int col;
	Organism** organisms;

	World* world;

	std::vector<Point> seekBuffer;

	int GetIndex(Point p);
};