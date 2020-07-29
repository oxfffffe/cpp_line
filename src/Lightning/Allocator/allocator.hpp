#define __ALLOCATOR_H
#ifdef  __ALLOCATOR_H

#include "src/Lightning/namespace/lightning.hpp"
//#include <bitset> ///> _GLIBCXX_BITSET

/*!
 * @brief Class represents memory allocator
 * without specifying size of the memory space
 */
class lightning::Allocator
{
public:
	template <typename T>
	static T* allocate(void)
	{
		int i = 0;
		do
		{
			i = freeblock; ///< assign freeblock falue to i
#ifdef _GLIBCXX_BITSET
			if (!bufmap.test(i))
			{
				break;
			}
#else
			if (!(i & 0x100))
			{
				break;
			}
#endif
		} while (i++ < 64);
		freeblock = ++i; ///< increment freeblock
		return new (&buffer[128*i]) T();
	}

	template <typename T>
	static void deallocate(T* ptr)
	{
		*ptr = 0;
	}

/*!
 * @variable int freeblock
 * @variable bufmap
 * @variable char buffer[2048]
 */
private:
	static char buffer[2048];
#ifdef _GLIBCXX_BITSET
	static std::bitset<1000> bufmap;
#endif
	static int  freeblock;
};

int lightning::Allocator::freeblock = 0;
#ifdef _GLIBCXX_BITSET
std::bitset<1000> lightning::Allocator::bufmap = std::bitset<1000>();
#endif
char lightning::Allocator::buffer[2048];
#endif
