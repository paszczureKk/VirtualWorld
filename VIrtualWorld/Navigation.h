#pragma once

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
};

namespace Navigation {
	Point Translate(Point p) {
		int dir = Utilities::random(0, DIRECTIONS_COUNT);

		Point point = { p.x, p.y };

		switch (dir) {
			case NORTH:
				point.x++;
				break;
			case EAST:
				point.y++;
				break;
			case SOUTH:
				point.x--;
				break;
			case WEST:
				point.y--;
				break;
		}

		return point;
	}
}