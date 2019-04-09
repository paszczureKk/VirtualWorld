#pragma once

#include <string>
#include <sstream>

enum WorldDirections {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	DIRECTIONS_COUNT,
	DIR_NULL
};

struct Point {
	int x;
	int y;

	bool operator==(Point other) {
		return (this->x == other.x && this->y == other.y);
	}
	std::string ToString() {
		std::stringstream ss;

		ss << '(' << x << ',' << y << ')';

		return ss.str();
	}
};
const struct Point NULL_POINT = { -1, -1 };

namespace Navigation {
	Point Translate(Point p, WorldDirections = DIR_NULL);
}