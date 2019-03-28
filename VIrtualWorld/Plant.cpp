#include "Plant.h"

Plant::Plant(int s, int a, Point p, World& w) : Organism(s, 0, a, p, w) {}

void Plant::Action() {}
void Plant::Collision() {}
void Plant::Draw() {}