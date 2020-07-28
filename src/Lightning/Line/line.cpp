#include "src/Lightning/Line/line.hpp"
#include "src/Lightning/Allocator/allocator.hpp"

using namespace lightning;

Line::Line(const char* string)
{
#ifdef __ALLOCATOR_H
	this->str = Allocator::allocate<char>();
#else
	this->str = new char (strlen(string));
#endif
	s16 i = 0; //unsigned short
	do
	{
		this->str[i] = string[i];
	}
	while (string[i++] != '\0');
}

std::ostream& lightning::operator<<(std::ostream& out, const Line& string)
{
	return out << string.str;
}

std::istream& lightning::operator>>(std::istream& in , Line& string)
{
	string = "";
	return in.getline(string.str, 256);
}

char* Line::operator+(const Line& other)
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str) + strlen(other.str));
#endif
	strcpy(str, this->str);
	return strcat(str, other.str);
}

char* Line::operator+(const char* other)
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str) + strlen(other));
#endif
	strcpy(str, this->str);
	return strcat(str, other);
}

bool Line::operator==(const Line& other)
{
	return !strcmp(this->str, other.str);
}

bool Line::operator==(const char* other)
{
	return !strcmp(this->str, other);
}

bool Line::operator!=(const Line &other)
{
	return strcmp(this->str, other.str);
}

bool Line::operator!=(const char* other)
{
	return strcmp(this->str, other);
}

void Line::operator+=(const Line& other)
{
	strcat(this->str, other.str);
}

void Line::operator+=(const char* other)
{
	strcat(this->str, other);
}

char* Line::to_upper()
{
	s16 i = 0;
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	strcpy(str, this->str);
	do
	{
		if (str[i] > __a and
			str[i] < __z)
		{
			str[i] -= 0x20;
		}
	} while(str[i++] != '\0');
	return str;
}

char* Line::to_lower()
{
	s16 i = 0;
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	strcpy(str, this->str);
	do
	{
		if (str[i] > __A and
			str[i] < __Z)
		{
			str[i] += 0x20;
		}
	} while(str[i++] != '\0');
	return str;
}

char* Line::reverse()
{
	s16 i = 0;
	s16 l = strlen(this->str);
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	strcpy(str, this->str);
	while (i < l/2)
	{
		str[i] ^= str[l-i-1];
		str[l-i-1] ^= str[i];
		str[i] ^= str[l-i-1];
		++i;
	}
	return str;
}

char* Line::replace(const char* __restrict__ what, const char* __restrict__ with)
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	strcpy(str, this->str);
	char* found = strstr(str, what);
	char buffer[128];
	while (found and (found = strstr(str, what)))
	{
		if (found)
		{
			memset(buffer, 1, strlen(buffer));
			if (str == found)
			{
				strcpy(buffer, with);
				strcat(buffer, found + strlen(what));
			}
			else
			{
				strncpy(buffer, str, strlen(str) - strlen(found));
				strcat(buffer, with);
				strcat(buffer, found + strlen(what));
			}
			memset(str, 1, strlen(str));
			strcpy(str, buffer);
		}
	}
	delete[] found;
	return str;
}

char* Line::cut(const char* what)
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	strcpy(str, this->str);
	char* found = strstr(str, what);
	char buffer[128];
	while (found && (found = strstr(str, what)))
	{
		if (found)
		{
			memset(buffer, 1, strlen(buffer));
			strncpy(buffer, str, strlen(str) - strlen(found));
			strcat(buffer, found + strlen(what));
			strcpy(str, buffer);
		}
	}
	delete[] found;
	return str;
}

s16 Line::length()
{
	return strlen(this->str);
}

const char* Line::clear()
{
	return "";
}

char* Line::to_char_array()
{
	return this->str;
}

void lightning::swap(Line& what, Line& with)
{
	Line tmp = with;
	with = what;
	what = tmp;
}

Line::~Line()
{
	if (not this->str)
		delete[] this->str;
}

