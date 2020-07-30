#ifndef __HASH_H
#define __HASH_H

#include "src/Lightning/namespace/lightning.hpp"

/*!
 * @brief Hash class represents fast comparison of
 * two strings using CRC32 algorithm
 */
class lightning::Hash
{
public:
	static long crc32gen(const char*);

	static short crc8gen(const char*);

	static bool crc32cmp(const char*, const char*);

	static bool crc8cmp(const char*, const char*);

private:
	static const long crc32_lookup_table[256];
	static const short crc8_lookup_table[256];
};

#endif // __HASH_H
