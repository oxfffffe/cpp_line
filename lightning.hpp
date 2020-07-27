#include "line.hpp"

namespace lightning
{
	class Line;
	class Regex;
	class Allocator;
	void  swap(Line&, Line&);
#ifndef  _STRING_H
	int   strlen(const char*);
	bool  strcmp(char*, const char*);
	void* memset(void*, int, int);
	char* strcpy(char*, const char*);
	char* strncpy(char*, const char*, size_t);
	char* strcat(char*, const char*);
	char* strstr(char*, const char*);
#endif // _STRING_H
}
