#include "Utilities.h"
#include <cstdlib>
#include <time.h>

namespace Utilities {
	void init() {
		srand(time(NULL));
	}
	float random(float min, float max) {
		return rand() / (RAND_MAX / (max - min) ) + min;
	}
	int random(int min, int max) {
		return rand() % max + min;
	}
}