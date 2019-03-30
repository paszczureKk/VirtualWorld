#pragma once

#include "Navigation.h"
class World;

class Organism {
	public :
		Organism(int s, int i, int a, Point l, World* w);

		virtual void Action() = 0;
		virtual void Collision() = 0;
		virtual void Draw() = 0;

		static bool Compare(Organism* current, Organism* other);
	protected:
		int strength;
		int initiative;
		int age;
		Point location;
		World* world;
	private :
};