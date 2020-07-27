#include "line.hpp"
#include "allocator.hpp"

using namespace lightning;

Line::Line(const char* string)
{
	this->__str = Allocator::allocate<char>();
	s16 i = 0;
	do
	{
		this->__str[i] = string[i];
	}
	while (string[i++] != '\0');
}

std::ostream& lightning::operator<<(std::ostream& out, const Line& string)
{
	return out << string.__str;
}

std::istream& lightning::operator>>(std::istream& in , Line& string)
{
	string = "";
	return in.getline(string.__str, 256);
}

char* Line::operator+(Line& other)
{
	char* str = Allocator::allocate<char>();
	strcpy(str, this->__str);
	return strcat(str, other.__str);
}

char* Line::operator+(const char* other)
{
	char* str = Allocator::allocate<char>();
	strcpy(str, this->__str);
	return strcat(str, other);
}

bool Line::operator==(Line& other)
{
	return strcmp(this->__str, other.__str);
}

bool Line::operator==(const char* other)
{
	return strcmp(this->__str, other);
}

bool Line::operator!=(Line &other)
{
	return !strcmp(this->__str, other.__str);
}

bool Line::operator!=(const char* other)
{
	return !strcmp(this->__str, other);
}

void Line::operator+=(Line& other)
{
	strcat(this->__str, other.__str);
}

void Line::operator+=(const char* other)
{
	strcat(this->__str, other);
}

char* Line::to_upper()
{
	s16 i = 0;
	char* str = Allocator::allocate<char>();
	strcpy(str, this->__str);
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
	char* str = Allocator::allocate<char>();
	strcpy(str, this->__str);
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
	s16 l = strlen(this->__str);
	char* str = Allocator::allocate<char>();
	strcpy(str, this->__str);
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
	char* str = Allocator::allocate<char>();
	strcpy(str, this->__str);
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
	char* str = Allocator::allocate<char>();
	strcpy(str, this->__str);
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
	return strlen(this->__str);
}

const char* Line::clear()
{
	return "";
}

Line::~Line()
{
	if (not this->__str)
		delete[] this->__str;
}
