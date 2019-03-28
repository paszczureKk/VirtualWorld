#pragma once

#include "Headers.h"
#include "Navigation.h"

class Organism {
	public :
		Organism(int s, int i, int a, Point l, World& w);

		virtual void Action() = 0;
		virtual void Collision() = 0;
		virtual void Draw() = 0;

		static bool Compare(Organism* current, Organism* other);
	private :
		int strength;
		int initiative;
		int age;
		Point location;
		World* world;
		int *p;
};