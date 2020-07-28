#pragma once

#include <string.h> // strcat, strcmp, ...
#include <ostream>
#include <istream>
#include "src/Lightning/namespace/lightning.hpp"
#include "src/defines.hpp" // unsigned short -> s16

class lightning::Line
{
public:
	Line(){};

/* initialize private field __str */
	Line(const char*);

	~Line();

	friend std::ostream&
	operator<<(std::ostream&, const Line&);

	friend std::istream&
	operator>>(std::istream&, Line&);

/* concatenate this->__str with Line&.__str and return result */
	char*
	operator+(const Line&);

/* concatenate this->__str with char array and return result */
	char*
	operator+(const char*);

/* compare if this->__str == Line&.__str */
	bool
	operator==(const Line&);

/* compare if this->__str == char* */
	bool
	operator==(const char*);

/* compare if this->__str != Line&.__str */
	bool
	operator!=(const Line&);

/* compare if this->__str != char* */
	bool
	operator!=(const char*);

/* concatenate this->__str with Line&.__str and return result */
	void
	operator+=(const Line&);

/* concatenate this->__str with char* and return result */
	void
	operator+=(const char*);

	char* to_upper();

	char* to_lower();

	char* reverse();

/* return this->__str (needed by Regex class to avoid creating an friend class) */
	char* to_char_array();

	char* replace(const char* __restrict__, const char* __restrict__);

	char* cut(const char*);

/* return length of this->__str */
	s16 length();

/* return empty string */
	const char* clear();

private:
	char* __str;
};

