#include "Navigation.h"
#include "Utilities.h"

namespace Navigation {
	Point Translate(Point p, WorldDirections dir) {
		if (dir == DIR_NULL) {
			dir = (WorldDirections)Utilities::random(0, DIRECTIONS_COUNT);
		}

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