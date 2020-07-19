#include "line.hpp"
#include "defines.hpp"

lightning::line::line(const char* string)
{
	unsigned short length = strlen(string);
	this->__str = new char[length + 1];
	for (unsigned short i = 0; i < length; i++)
	{
		this->__str[i] = string[i];
	}
	this->__str[length] = '\0';
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

lightning::line lightning::line::operator+(line& other)
{
	unsigned short other_length = strlen(other.__str);
	line new_string;
	new_string.__str = new char[strlen(this->__str) + other_length + 1];

	unsigned short i = 0;
	for ( ; i < strlen(this->__str); i++)
	{
		new_string.__str[i] = this->__str[i];
	}
	for (unsigned short j = 0; j < other_length; j++)
	{
		new_string.__str[i + j] = other.__str[j];
	}
	return new_string;
}

lightning::line lightning::line::operator+(const char* other)
{
	unsigned short other_length = strlen(other);
	line new_string;
	new_string.__str = new char[strlen(this->__str) + other_length + 1];

	unsigned short i = 0;
	for ( ; i < strlen(this->__str); i++)
	{
		new_string.__str[i] = this->__str[i];
	}
	for (unsigned short j = 0; j < other_length; j++)
	{
		new_string.__str[i + j] = other[j];
	}
	return new_string;
}

void lightning::line::operator+=(line& other)
{
	unsigned short other_length = strlen(other.__str);
	unsigned short i = 0;
	for ( ; i < strlen(this->__str); i++)
	{
		this->__str[i] = this->__str[i];
	}
	for (unsigned short j = 0; j < other_length; j++)
	{
		this->__str[i + j] = other.__str[j];
	}
}

void lightning::line::operator+=(const char* other)
{
	unsigned short other_length = strlen(other);
	unsigned short i = 0;
	for ( ; i < strlen(this->__str); i++)
	{
		this->__str[i] = this->__str[i];
	}
	for (unsigned short j = 0; j < other_length; j++)
	{
		this->__str[i + j] = other[j];
	}
}

bool lightning::line::operator==(line& other)
{
	return !strcmp(this->__str, other.__str);
}

bool lightning::line::operator==(const char* other)
{
	return !strcmp(this->__str, other);
}

bool lightning::line::operator!=(line &other)
{
	return strcmp(this->__str, other.__str);
}

bool lightning::line::operator!=(const char* other)
{
	return strcmp(this->__str, other);
}

char* lightning::line::to_upper()
{
	for (unsigned short i = 0; i < strlen(this->__str); i++)
	{
		if (this->__str[i] > __a &&
			this->__str[i] < __z)
		{
			this->__str[i] -= 32;
		}
	}
	return this->__str;
}

char* lightning::line::to_lower()
{
	for (unsigned short i = 0; i < strlen(this->__str); i++)
	{
		if (this->__str[i] > __A &&
			this->__str[i] < __Z)
		{
			this->__str[i] += 32;
		}
	}
	return this->__str;
}

char* lightning::line::reverse()
{
	unsigned short length = strlen(this->__str);
	for (unsigned short i = 0; i < length/2; i++)
	{
		char tmp = this->__str[i];
		this->__str[i] = this->__str[length-i-1];
		this->__str[length-i-1] = tmp;
	}
	return this->__str;
}

char* lightning::line::replace(const char* what, const char* with)
{
	char* found = strstr(this->__str, what);
	char buffer[256];
	while (found && (found = strstr(this->__str, what)))
	{
		if (found)
		{
			memset(buffer, '\0', strlen(buffer));
			if (this->__str == found)
			{
				strcpy(buffer, with);
				strcat(buffer, found + strlen(what));
			}
			else
			{
				strncpy(buffer, this->__str, strlen(this->__str) - strlen(found));
				strcat(buffer, with);
				strcat(buffer, found + strlen(what));
			}
			memset(this->__str, '\0', strlen(this->__str));
			strcpy(this->__str, buffer);
		}
	}
	delete[] found;
	return this->__str;
}

char* lightning::line::replace(std::regex regex, const char* with)
{
	std::string matched = std::regex_replace(this->__str, regex, with);
	char* result = new char[matched.length() + 1];
	return strcpy(result, matched.c_str());
}

char* lightning::line::cut(const char* what)
{
	char* found = strstr(this->__str, what);
	char buffer[256];
	while (found && (found = strstr(this->__str, what)))
	{
		if (found)
		{
			memset(buffer, '\0', strlen(buffer));
			strncpy(buffer, this->__str, strlen(this->__str) - strlen(found));
			strcat(buffer, found + strlen(what));
			strcpy(this->__str, buffer);
		}
	}
	delete[] found;
	return this->__str;
}

unsigned short lightning::line::length()
{
	unsigned short length = 0;
	while (this->__str[length] != '\0')
	{
		++length;
	}
	return length;
}

const char* lightning::line::clear()
{
	return "";
}

void lightning::swap(line& what, line& with)
{
	line tmp = with;
	with = what;
	what = tmp;
}

lightning::line::~line()
{
	if (this->__str == NULL)
		delete[] this->__str;
}
