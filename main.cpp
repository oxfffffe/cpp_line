#include "line.hpp"
#include "defines.hpp"

int main(void)
{
#ifdef	__START_TIME
		__START_TIME
#endif
#ifdef	__DEBUG
	line a;
	std::cin >> a;
	std::cout << a.replace(std::regex("\\d"), "_") << std::endl;
#endif//__DEBUG
#ifdef	__FINISHED_AT
		__FINISHED_AT
#endif
}
