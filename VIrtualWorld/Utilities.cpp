#include "Utilities.h"
#include <cstdlib>
#include <time.h>

#include "conio2.h"

namespace Utilities {
	void init() {

		#ifndef __cplusplus
				Conio2_Init();
		#endif


		textmode(C4350);

		// settitle sets the window title
		settitle("VirtualWorld Daniel Szynszecki 175683");

		// hide the blinking cursor
		_setcursortype(_NOCURSOR);

		srand(time(NULL));
	}
	float random(float min, float max) {
		return rand() / (RAND_MAX / (max - min) ) + min;
	}
	int random(int min, int max) {
		return rand() % max + min;
	}
}