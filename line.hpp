#pragma once

//#include <string.h>
#include <ostream>
#include <istream>
#include "lightning.hpp"
#include "defines.hpp"
//#include "allocator.hpp"

class lightning::Line
{
public:
	Line(){};
	Line(const char*);
	~Line();
	friend std::ostream& operator<<(std::ostream&, const Line&);
	friend std::istream& operator>>(std::istream&, Line&);
	char* operator+(Line&);
	char* operator+(const char*);
	bool  operator==(Line&);
	bool  operator==(const char*);
	bool  operator!=(Line&);
	bool  operator!=(const char*);
	void  operator+=(Line&);
	void  operator+=(const char*);
	char* to_upper();
	char* to_lower();
	char* reverse();
	char* replace(const char* __restrict__, const char* __restrict__);
	char* cut(const char*);
	s16 length();
	const char* clear();
	friend class lightning::Regex;
private:
	char* __str;
};
