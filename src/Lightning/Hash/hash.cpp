#include "hash.hpp"

#define POLYNOMIAL 0xEDB88320UL

uint32_t lightning::Hash::crc32gen(const char* buf)
{
	int len = 0;
	do
	{
		++len;
	} while(buf[len] != '\0');

	uint32_t crc32_table[256];
	uint32_t crc32;
	for (int i = 0; i < 256; i++)
	{
		crc32 = i;
		for (int j = 0; j < 8; j++)
		{
			crc32 = crc32 & 1 ? (crc32 >> 1) ^ POLYNOMIAL : crc32 >> 1;
		}
		crc32_table[i] = crc32;
	}
	crc32 = 0xFFFFFFFFUL;
	while (len--)
	{
		crc32 = crc32_table[(crc32 ^ *buf++) & 0xFF] ^ (crc32 >> 8);
	}
	return crc32 ^ 0xFFFFFFFFUL;
}

bool lightning::Hash::crc32cmp(const char* what, const char* with)
{
	return (crc32gen(what) == crc32gen(with));
}
