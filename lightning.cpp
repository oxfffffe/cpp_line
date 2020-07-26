#include "lightning.hpp"
#include "line.hpp"

void lightning::swap(line& what, line& with)
{
	line tmp = with;
	with = what;
	what = tmp;
}

#ifndef	_STRING_H
int lightning::strlen(const char* string)
{
	int index = 0;
	do {} while (string[++index] != '\0');
	return index;
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

/* Set __count bytes of __block to __byte.  */
void* lightning::memset(void* __block, int __byte, int __count)
{
	 unsigned char* __ptr =
	(unsigned char*)__block;
	while (__count-- > 0)
		*__ptr++ = __byte;
	return __block;
}

char* lightning::strcpy(char* buffer, const char* string)
{
	char* copied = buffer;
	while (*string)
	{
		*buffer++ = *string++;
	}
	return copied;
}

char* lightning::strcat(char* what, const char* with)
{
	char* result = new char(strlen(what) + strlen(with));
	s16 i = 0;
	s16 j = 0;
	while (what[i] != '\0')
	{
		result[i] = what[i];
		++i;
	}
	while (with[j] != '\0')
	{
		result[i+j] = with[j];
		++j;
	}
	return result;
}

char* lightning::strstr(char* string, const char* substring)
{
	const char *a, *b;

	b = substring;
	if (*b == 0)
	{
		return string;
	}
	for ( ; *string != 0; string += 1)
	{
		if (*string != *b)
		{
			continue;
		}
		a = string;
		while (1)
		{
			if (*b == 0)
			{
				return string;
			}
			if (*a++ != *b++)
			{
				break;
			}
		}
		b = substring;
	}
	return __null;
}

char* lightning::strncpy(char* where, const char* what, size_t count)
{
	if (count != 0)
	{
		char* buffer = where;
		const char* src = what;
		do
		{
			if ((*buffer++ = *src++) == 0)
			{
				while (--count != 0)
				{
					*buffer++ = 0;
				}
				break;
			}
		} while(--count != 0);
	}
	return where;
}

#endif // _STRING_H











