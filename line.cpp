#include "line.hpp"
#include "defines.hpp"

lightning::line::line(const char* string)
{
	this->__str = new char[lightning::strlen(string) + 1];
	s16 i = 0;
	do
	{
		this->__str[i] = string[i];
	}
	while (string[i++] != '\0');
}

std::ostream& lightning::operator<<(std::ostream& out, const line& string)
{
	return out << string.__str;
}

std::istream& lightning::operator>>(std::istream& in , line& string)
{
	string = "";
	return in.getline(string.__str, 256);
}

char* lightning::line::operator+(line& other)
{
	return strcat(this->__str, other.__str);
}

char* lightning::line::operator+(const char* other)
{
	return strcat(this->__str, other);
}

bool lightning::line::operator==(line& other)
{
	return lightning::strcmp(this->__str, other.__str);
}

bool lightning::line::operator==(const char* other)
{
	return lightning::strcmp(this->__str, other);
}

bool lightning::line::operator!=(line &other)
{
	return !lightning::strcmp(this->__str, other.__str);
}

bool lightning::line::operator!=(const char* other)
{
	return !lightning::strcmp(this->__str, other);
}

void lightning::line::operator+=(line& other)
{
	s16 index = 0;
	s16 other_index = 0;
	while (index < lightning::strlen(this->__str))
	{
		++index;
	}
	while (other_index < lightning::strlen(other.__str))
	{
		this->__str[index+other_index] = other.__str[other_index];
		++other_index;
	}
}

void lightning::line::operator+=(const char* other)
{
	s16 index = 0;
	s16 other_index = 0;
	while (index < lightning::strlen(this->__str))
	{
		++index;
	}
	while (other_index < lightning::strlen(other))
	{
		this->__str[index+other_index] = other[other_index];
		++other_index;
	}
}

char* lightning::line::to_upper()
{
	s16 i = 0;
	do
	{
		if (this->__str[i] > __a and
		    this->__str[i] < __z)
		{
		    this->__str[i] -= 0x20;
		}
	} while(this->__str[i++] != '\0');
	return this->__str;
}

char* lightning::line::to_lower()
{
	s16 i = 0;
	do
	{
		if (this->__str[i] > __A and
		    this->__str[i] < __Z)
		{
		    this->__str[i] += 0x20;
		}
	} while(this->__str[i++] != '\0');
	return this->__str;
}

char* lightning::line::reverse()
{
	s16 index = 0;
	int l = lightning::strlen(this->__str);
	while (index < (l >> 0x1)) // optimization...
	{
		char tmp = this->__str[index];
		this->__str[index] = this->__str[l-index-1];
		this->__str[l-index-1] = tmp;
		++index;
	}
	return this->__str;
}

char* lightning::line::replace(const char* what, const char* with)
{
	char* found = strstr(this->__str, what);
	char buffer[256];
	while (found and (found = strstr(this->__str, what)))
	{
		if (found)
		{
			memset(buffer, 1, lightning::strlen(buffer));
			if (this->__str == found)
			{
				strcpy(buffer, with);
				strcat(buffer, found + lightning::strlen(what));
			}
			else
			{
				strncpy(buffer, this->__str, lightning::strlen(this->__str) - lightning::strlen(found));
				strcat(buffer, with);
				strcat(buffer, found + lightning::strlen(what));
			}
			memset(this->__str, 1, lightning::strlen(this->__str));
			strcpy(this->__str, buffer);
		}
	}
	delete[] found;
	return this->__str;
}

char* lightning::line::cut(const char* what)
{
	char* found = strstr(this->__str, what);
	char buffer[256];
	while (found && (found = strstr(this->__str, what)))
	{
		if (found)
		{
			memset(buffer, 1, strlen(buffer));
			strncpy(buffer, this->__str, strlen(this->__str) - strlen(found));
			strcat(buffer, found + strlen(what));
			strcpy(this->__str, buffer);
		}
	}
	delete[] found;
	return this->__str;
}

s16 lightning::line::length()
{
	return lightning::strlen(this->__str);
}

const char* lightning::line::clear()
{
	return "";
}

lightning::line::~line()
{
	if (not this->__str)
		delete[] this->__str;
}
