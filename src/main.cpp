#include "src/Lightning/Line/line.hpp"
#include "src/Lightning/Regex/regex.hpp"
#include <iostream>

using lightning::Line;
using lightning::Regex;
using std::cout;
using std::endl;

auto main() -> int
{
#ifdef	__START_TIME
        __START_TIME
#endif
#ifdef	__DEBUG_LINE
//	std::ios::sync_with_stdio(false);
	Line a = "std::ios::sync_with_stdio(false))))))";
	std::cout << "first string: \t\t\t\t" << a << std::endl;
	std::cout << "length of first string: \t\t" << a.length() << std::endl;
	std::cout << "reverse first string: \t\t\t" << a.reverse() << std::endl;
	std::cout << "cut \" \" from first string: \t\t" << a.cut(" ") << std::endl;		// [!!!] BUG
//	std::cout << "replace \"!\" with \"?\": \t\t\t" << a.replace(":", "1") << std::endl;
	std::cout << "convert first string to uppercase: \t" << a.to_upper() << std::endl;
	std::cout << "convert first string to lowercase: \t" << a.to_lower() << std::endl;
	std::cout << "concatenate first string with \"[0-9]+\":\t" << a + " [0-9]+" << std::endl;
	std::cout << "concatenate first string with itself: \t" << a + a << std::endl;
	std::cout << "clear first string: \t" << a.clear()	<< std::endl;
	std::cout << "first string == itself: \t\t" << (a == a) << std::endl;
	std::cout << "first string != itself: \t\t" << (a != a) << std::endl;
	std::cout << "first string == \"123\": \t\t\t" << (a == "123") << std::endl;
	std::cout << "first string != \"123\": \t\t\t" << (a != "123") << std::endl;
	std::cout << "match text (regex): \t\t\t" << Regex::match_exists(".*world", a.to_char_array()) << std::endl;
#endif//__DEBUG_LINE
#ifdef	__DEBUG_REGEX
	regex pattern = "[0] !//[regular expression]";
	std::cout << regex::regex_find(pattern, "\\S+\\s\\S+\\s\\S+") << std::endl;
#endif//__DEBUG_REGEX
#ifdef	__FINISHED_AT
        __FINISHED_AT
#endif
}
