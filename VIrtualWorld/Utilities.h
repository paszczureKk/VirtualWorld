#pragma once

#include <string>

namespace Utilities {
	void init();
	float random(float min, float max);
	int random(int min, int max);
	void print(std::string s);
	constexpr unsigned int str2int(const char* str, int h = 0) {
		return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
	}
}