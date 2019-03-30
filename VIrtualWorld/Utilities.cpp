#include <cstdlib>

namespace Utilities {
	float random(float min, float max) {
		return 0;
	}
	int random(int min, int max) {
		return rand() % max + min;
	}
}