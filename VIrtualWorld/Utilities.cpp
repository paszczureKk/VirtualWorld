#include "Utilities.h"
#include <cstdlib>
#include <time.h>
#include <string>

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

		srand((unsigned int)time(NULL));
		for (int i = 0; i < 100; i++) {
			rand();
		}
	}
	float random(float min, float max) {
		return rand() / (RAND_MAX / (max - min) ) + min;
	}
	int random(int min, int max) {
		return rand() % max + min;
	}
	void print(std::string s) {
		for (int i = 0; s[i] != '\0'; i++) {
			putch(s[i]);
		}
	}
}