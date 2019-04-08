#pragma once

#include <string>

enum WorldDirections {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	DIRECTIONS_COUNT
};

struct Point {
	int x;
	int y;

	bool operator==(Point other) {
		return (this->x == other.x && this->y == other.y);
	}
	std::string ToString() {
		std::string a;
		a += "(";
		a += x;
		a += ",";
		a += y;
		a += ")";
		return a;
	}
};
const struct Point NULL_POINT = { -1, -1 };

namespace Navigation {
	Point Translate(Point p);
}