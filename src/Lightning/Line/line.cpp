#include "src/Lightning/Line/line.hpp"
#include "src/Lightning/Allocator/allocator.hpp"
//#include "src/Lightning/Hash/hash.hpp"

using namespace lightning;

Line::Line(const char* string)
{
#ifdef __ALLOCATOR_H
	this->str = Allocator::allocate<char>();
#else
	this->str = new char (strlen(string));
#endif
	memcpy(this->str, string, strlen(string));
}

std::ostream& lightning::operator<<(std::ostream& out, const Line& string) noexcept
{
	return out << string.str;
}

std::istream& lightning::operator>>(std::istream& in , Line& string) noexcept
{
	string = "";
	return in.getline(string.str, 256);
}

char* Line::operator+(const Line& other) noexcept
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str) + strlen(other.str));
#endif
	return strcat(strcpy(str, this->str), other.str);
}

char* Line::operator+(const char* other) noexcept
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str) + strlen(other));
#endif
	return strcat(strcpy(str, this->str), other);
}

bool Line::operator==(const Line& other) noexcept
{
#ifdef __HASH_H
	return Hash::crc32cmp(this->str, other.str);
#else
	return !strcmp(this->str, other.str);
#endif
}

bool Line::operator==(const char* other) noexcept
{
#ifdef __HASH_H
	return Hash::crc32cmp(this->str, other);
#else
	return !strcmp(this->str, other);
#endif
}

bool Line::operator!=(const Line &other) noexcept
{
#ifdef __HASH_H
	return !Hash::crc32cmp(this->str, other.str);
#else
	return strcmp(this->str, other.str);
#endif
}

bool Line::operator!=(const char* other) noexcept
{
#ifdef __HASH_H
	return !Hash::crc32cmp(this->str, other);
#else
	return strcmp(this->str, other);
#endif
}

void Line::operator+=(const Line& other) noexcept
{
	strcat(this->str, other.str);
}

void Line::operator+=(const char* other) noexcept
{
	strcat(this->str, other);
}

char* Line::to_upper() noexcept
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	s16 i = 0;
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

char* Line::to_lower() noexcept
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	s16 i = 0;
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

char* Line::reverse() noexcept
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
		/*!
		 * @brief reverse using XOR
		 */
		str[i] ^= str[l-i-1];
		str[l-i-1] ^= str[i];
		str[i] ^= str[l-i-1];
		++i;
	}
	return str;
}

char* Line::replace(const char* __restrict__ what, const char* __restrict__ with) noexcept
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

char* Line::cut(const char* what) noexcept
{
#ifdef __ALLOCATOR_H
	char* str = Allocator::allocate<char>();
#else
	char* str = new char(strlen(this->str));
#endif
	strcpy(str, this->str);
	char* found = strstr(str, what);
	char buffer[128];
	while (found)
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

s16 Line::length() noexcept
{
	return strlen(this->str);
}

const char* Line::clear() noexcept
{
	return "";
}

char* Line::to_char_array() noexcept
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
