#include "line.hpp"
#include "regex.hpp"
#include <iostream>

using lightning::line;
using lightning::regex;

int main(void)
{
#ifdef	__START_TIME
        __START_TIME
#endif
#ifdef	__DEBUG_LINE
	line a = "[0] !//[regex]";
	line b = "swapped!";
	lightning::swap(a, b);
	std::cout << "first string: \t\t\t\t" << a << std::endl;
	std::cout << "length of first string: \t\t" << a.length() << std::endl;
	std::cout << "reverse first string: \t\t\t" << a.reverse() << std::endl;
	std::cout << "clear first string: \t" << a.clear()	<< std::endl;
	std::cout << "cut \" \" from first string: \t\t" << a.cut(" ") << std::endl;
	std::cout << "replace space with \"_\" (default): \t" << a.replace("!", "?") << std::endl;
	std::cout << "convert first string to uppercase: \t" << a.to_upper() << std::endl;
	std::cout << "convert first string to lowercase: \t" << a.to_lower() << std::endl;
	std::cout << "concatenate first string with \"[0-9]+\":\t" << a + " [0-9]+" << std::endl;
	std::cout << "concatenate first string with itself: \t" << a + a << std::endl;
	std::cout << "first string == itself: \t\t" << (a == a) << std::endl;
	std::cout << "first string != itself: \t\t" << (a != a) << std::endl;
	std::cout << "first string == \"123\": \t\t\t" << (a == "123") << std::endl;
	std::cout << "first string != \"123\": \t\t\t" << (a != "123") << std::endl;
	std::cout << "first string: \t\t\t\t" << a << std::endl;
	std::cout << "match text (regex): \t\t\t" << regex::match_exists("[0]\\s!//[regex]", a) << std::endl;
#endif//__DEBUG
#ifdef	__DEBUG_REGEX
	regex pattern = "[0] !//[regular expression]";
	std::cout << regex::regex_find(pattern, "\\S+\\s\\S+\\s\\S+") << std::endl;
#endif//__DEBUG_REGEX
#ifdef	__FINISHED_AT
        __FINISHED_AT
#endif
}
