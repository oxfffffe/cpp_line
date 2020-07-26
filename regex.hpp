#pragma once

#include "line.hpp"

class lightning::regex
{
public:
	static bool match_exists(const char* regex, line string);
private:
	static inline bool match_group(int ch, int group);
	static inline bool match_quantity(const char* regex, char* string, int quant, int ch, int* len);
};
