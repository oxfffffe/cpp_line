#pragma once

#include "lightning.hpp"

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
		} while (i++ < 128);
		freeblock = ++i;
		return static_cast<T*>
		(
			new (&buffer[32*i]) T()
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
