#include "lightning.hpp"
#include "line.hpp"

int lightning::strlen(const char* string)
{
	int index = 0;
	do {} while (string[++index] != '\0');
	return index;
}

void lightning::swap(line& what, line& with)
{
	line tmp = with;
	with = what;
	what = tmp;
}

bool lightning::strcmp(char* what, const char* with)
{
	if (strlen(what) ==
		strlen(with))
	{
		int index = 0;
		int c1 = what[index++];
		int c2 = with[index++];
		while (c1 == c2)
		{
			if (c1 != c2)
				return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}
