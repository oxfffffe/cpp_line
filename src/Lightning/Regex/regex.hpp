#include <ctype.h>
#include "src/Lightning/namespace/lightning.hpp"

class lightning::Regex
{
public:
	static bool match_exists(const char* regex, char* string);

private:
	static inline int strlen(char* string);

	static inline bool match_group(int ch, int group);

	static inline bool match_quantity(const char* regex, char* string, int quant, int ch, int* len);
};
