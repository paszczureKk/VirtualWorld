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
			point.y--;
			break;
		case EAST:
			point.x++;
			break;
		case SOUTH:
			point.y++;
			break;
		case WEST:
			point.x--;
			break;
		}

		return point;
	}
	std::string ToString(WorldDirections dir) {

		switch (dir) {
			case NORTH:
				return "North";
			case EAST:
				return "East ";
			case SOUTH:
				return "South";
			case WEST:
				return "West ";
			default:
				return "";
			}
	}
}