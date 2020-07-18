#pragma once

#include <iostream>
#include <regex>

class line
{
public:
	line(){};
	line(const char*);
	~line();
	friend std::ostream& operator<<(std::ostream&, const line&);
	friend std::istream& operator>>(std::istream&, line&);
	line operator+ (line&);
	line operator+ (const char*);
	void operator+=(line&);
	void operator+=(const char*);
	bool operator==(line&);
	bool operator==(const char*);
	bool operator!=(line&);
	bool operator!=(const char*);
	char* to_upper();
	char* to_lower();
	char* reverse();
	char* replace(const char*, const char*);
	char* replace(std::regex, const char*); //don't use it please
	char* cut(const char*);
	unsigned short length();
	const char* clear();
private:
	char* __str;
};
