#include "Utilities.h"
#include <cstdlib>

namespace Utilities {
	float random(float min, float max) {

	}
	int random(int min, int max) {
		return rand() % max + min;
	}
}