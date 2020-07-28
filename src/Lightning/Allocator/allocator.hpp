#define __ALLOCATOR_H
#ifdef  __ALLOCATOR_H

#include "src/Lightning/namespace/lightning.hpp"
#include <bitset>

class lightning::Allocator
{
public:
	template <typename T>
	static T* allocate(void)
	{
		int i = 0;
		do
		{
			i = freeblock;
			if (!bufmap.test(i))
				break;
		} while (i++ < 64);
		freeblock = ++i;
		return static_cast<T*>
		(
			new (&buffer[128*i]) T()
		);
	}

	template <typename T>
	static T* deallocate(T* ptr)
	{
		*ptr = 0;
	}

private:
	static char buffer[2048];
	static std::bitset<1024> bufmap;
	static int  freeblock;
};

int lightning::Allocator::freeblock = 0;
std::bitset<1024> lightning::Allocator::bufmap = std::bitset<1024>();
char lightning::Allocator::buffer[2048];
#endif
