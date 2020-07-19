#include "line.hpp"
#include "defines.hpp"

int main(void)
{
#ifdef	__START_TIME
	__START_TIME
#endif
#ifdef	__DEBUG
	__namespace::line a = "a line";
	__namespace::line b = "b line";
	__namespace::swap(a, b);
	__namespace::swap(b, a);
	std::cout << "first string: \t\t\t\t" << a << std::endl;
	std::cout << "second string: \t\t\t\t" << b << std::endl;
	std::cout << "cut symbol \"e\" from first string: \t" << a.cut("e") << std::endl;
	std::cout << "clear first string: \t" << a.clear()	<< std::endl;
	std::cout << "length of first string: \t\t" << a.length() << std::endl;
	std::cout << "replace space with \"_\" (default): \t" << a.replace(" ", "_") << std::endl;
	std::cout << "replace space with \"_\" (regex): \t" << a.replace(std::regex("\\s"), "_") << std::endl;
	std::cout << "convert first string to lowercase: \t" << a.to_lower() << std::endl;
	std::cout << "convert first string to uppercase: \t" << a.to_upper() << std::endl;
	std::cout << "reverse first string: \t\t\t" << a.reverse() << std::endl;
	std::cout << "concatenate first string with itself: \t" << a + a << std::endl;
	std::cout << "concatenate first string with \"text\": \t" << a + " another text\t" << std::endl;
	std::cout << "first string == itself: \t\t" << (a == a) << std::endl;
	std::cout << "first string == itself: \t\t" << (a != a) << std::endl;
	std::cout << "first string == \"example text\": \t" << (a == "example text") << std::endl;
	std::cout << "first string != \"example text\": \t" << (a != "example text") << std::endl;
#endif//__DEBUG
#ifdef	__FINISHED_AT
	__FINISHED_AT
#endif
}
