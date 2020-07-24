#include "regex.hpp"

bool lightning::regex::match(const char* regex, line& string)
{
	unsigned int ch = regex[0];
	if (regex[0] == '\0')
	{
		return true;
	}
	if	(regex[0] == '\\' &&
		 regex[1] != '\0')
	{
		ch = regex[1];
		if (ch != '\\' &&
		    ch != '^'  &&
		    ch != '$'  &&
		    ch != '+'  &&
		    ch != '*'  &&
		    ch != '?')
		{
			ch |= 0x100;
		}
		regex++;
	}
	int q = regex[1];
	if (q == '*' ||
	    q == '+' ||
	    q == '-' ||
	    q == '?')
	{
		int len = strlen(string.__str);
		return matchQuantity(regex+2, string.__str, q, ch, &len);
	}
	else if (matchGroup(*string.__str, ch))
	{
		++string.__str;
		return match(++regex, string);
	}
	return 0;
}

bool lightning::regex::matchGroup(int ch, int group)
{
	if ((group & 0xff) == '.')
	{
		group ^= 0x100;
	}
	if (group < 0x100)
	{
		return ch == group;
	}
	switch (group & 0xff) /* get "mask" if group < 255 */
	{
		case '.': return  true;
		case 'd': return  isdigit(ch);
		case 'D': return !isdigit(ch);
		case 's': return  isspace(ch);
		case 'S': return !isspace(ch);
		case 'w': return (isalpha(ch) ||
				  isdigit(ch));
		case 'W': return!(isalpha(ch) ||
				  isdigit(ch));
	}
	return 0;
}

bool lightning::regex::matchQuantity(const char* regex, char* string, int quant, int ch, int* len)
{
	if (quant == '?')
	{
		if (matchGroup(*string, ch))
		{
			++string;
			++len;
		}
		line __line;
		__line.__str = string;
		return match(regex, __line);
	}

	if (quant == '+' ||
	    quant == '*')
	{
		char *p = string;
		for ( ; *p != '\0' && matchGroup(*p, ch); ++p)
			++len;

		if (quant == '+' && p == string) return 0;
		{
			do
			{
				line __line;
				__line.__str = p;
				if (regex::match(regex, __line))
				{
					return 1;
				}
			} while (p-- > string);
		}
	}
	return 0;
}
