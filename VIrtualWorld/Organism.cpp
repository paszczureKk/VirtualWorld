#include "World.h"

#include <string>

#include "conio2.h"

Organism::Organism(int s, int i, int a, char ch, World* w) {
	strength = s;
	initiative = i;
	age = a;
	location = NULL_POINT;
	image = ch;
	world = w;
	alive = true;
}

bool Organism::IsAlive() {
	return alive;
}

int Organism::GetStrength() {
	return strength;
}
Point Organism::GetLocation() {
	return location;
}
void Organism::SetLocation(Point p) {
	this->location.x = p.x;
	this->location.y = p.y;
}

bool Organism::Compare(Organism* current, Organism* other) {
	if ( current->initiative != other->initiative ) {
		return current->initiative > other->initiative;
	}
	else {
		return current->age > other->age;
	}
}

void Organism::Draw() {
	putch(image);
}

void Organism::Kill(std::string s) {
	alive = false;
	world->Notify(s);
	world->RemoveFromWorld(this);
}

void Organism::Buff(int value) {
	strength += value;
}

void Organism::Fight(Organism* o) {
	if (this->GetStrength() < o->GetStrength() == false) {
		Point p = o->GetLocation();
		o->Kill(this->ToString());
		this->Move(p);
	}
	else {
		this->Kill(o->ToString());
	}
}