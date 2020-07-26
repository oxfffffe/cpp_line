#include "line.hpp"
#include "defines.hpp"

using namespace lightning;

line::line(const char* string)
{
	this->__str = new char[strlen(string) + 1];
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

char* line::operator+(line& other)
{
	s16 l = strlen(this->__str);
	char* str = new char(l);
	strcpy(str, this->__str);
	return strcat(str, other.__str);
}

char* line::operator+(const char* other)
{
	s16 l = strlen(this->__str);
	char* str = new char(l);
	strcpy(str, this->__str);
	return strcat(str, other);
}

bool line::operator==(line& other)
{
	return strcmp(this->__str, other.__str);
}

bool line::operator==(const char* other)
{
	return strcmp(this->__str, other);
}

bool line::operator!=(line &other)
{
	return !strcmp(this->__str, other.__str);
}

bool line::operator!=(const char* other)
{
	return !strcmp(this->__str, other);
}

void line::operator+=(line& other)
{
	strcat(this->__str, other.__str);
}

void line::operator+=(const char* other)
{
	strcat(this->__str, other);
}

char* line::to_upper()
{
	s16 i = 0;
	s16 l = strlen(this->__str);
	char* str = new char(l);
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

char* line::to_lower()
{
	s16 i = 0;
	s16 l = strlen(this->__str);
	char* str = new char(l);
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

char* line::reverse()
{
	s16 i = 0;
	s16 l = strlen(this->__str);
	char* str = new char(l);
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

char* line::replace(const char* __restrict__ what, const char* __restrict__ with)
{
	s16 l = strlen(this->__str);
	char* str = new char(l);
	strcpy(str, this->__str);
	char* found = strstr(str, what);
	char buffer[256];
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

char* line::cut(const char* what)
{
	s16 l = strlen(this->__str);
	char* str = new char(l);
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

s16 line::length()
{
	return strlen(this->__str);
}

const char* line::clear()
{
	return "";
}

line::~line()
{
	if (not this->__str)
		delete[] this->__str;
}
