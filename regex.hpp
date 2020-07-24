#pragma once

#include "line.hpp"

class lightning::regex
{
public:
	static bool match(const char* regex, line& string);
private:
	static inline bool matchGroup(int ch, int group);
	static inline bool matchQuantity(const char* regex, char* string, int quant, int ch, int* len);
};
