#pragma once

#include <iostream>
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
	bool  operator==(line&);
	bool  operator==(const char*);
	bool  operator!=(line&);
	bool  operator!=(const char*);
	void  operator+=(line&);
	void  operator+=(const char*);
	char* to_upper();
	char* to_lower();
	char* reverse();
	char* replace(const char* __restrict__, const char* __restrict__);
	char* cut(const char*);
	s16 length();
	const char* clear();
	friend class lightning::regex;
private:
	char* __str;
};
