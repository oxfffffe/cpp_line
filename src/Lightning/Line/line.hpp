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

/* overloading default output stream */
	friend std::ostream&
	operator<<(std::ostream&, const Line&);

/* overloading default input stream */
	friend std::istream&
	operator>>(std::istream&, Line&);

/* concatenate this->str with Line&.str and return result */
	char*
	operator+(const Line&);

/* concatenate this->str with char array and return result */
	char*
	operator+(const char*);

	bool
	operator==(const Line&);

	bool
	operator==(const char*);

	bool
	operator!=(const Line&);

	bool
	operator!=(const char*);

/* concatenate this->str with Line&.str and return result */
	void
	operator+=(const Line&);

/* concatenate this->str with char* and return result */
	void
	operator+=(const char*);

	char* to_upper();

	char* to_lower();

	char* reverse();

/* return this->__str (needed by Regex class to avoid creating an friend class) */
	char* to_char_array();

	char* replace(const char* __restrict__, const char* __restrict__);

	char* cut(const char*);

	s16 length();

/* return empty string */
	const char* clear();

private:
	char* str;
};

