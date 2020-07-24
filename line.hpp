#pragma once

#include <string.h>
#include <istream>
#include "lightning.hpp"
#include "defines.hpp"

class lightning::line
{
public:
	line(){};
	line(const char*);
	~line();
	friend std::ostream& operator<<(std::ostream&, const line&);
	friend std::istream& operator>>(std::istream&, line&);
	char* operator+(line&);
	char* operator+(const char*);
	bool operator==(line&);
	bool operator==(const char*);
	bool operator!=(line&);
	bool operator!=(const char*);
	void operator+=(line&);
	void operator+=(const char*);
	char* to_upper();
	char* to_lower();
	char* reverse();
	char* replace(const char*, const char*);
	char* cut(const char*);
	s16 length();
	const char* clear();
	friend class lightning::regex;
private:
	char* __restrict __str;
};
