#include "Wolf.h"

Wolf::Wolf(int a, World* w) : Animal(9, 5, a, 'W', w) {}

std::string Wolf::ToString() {
	return "Wolf";
}