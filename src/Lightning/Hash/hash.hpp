#ifndef __HASH_H
#define __HASH_H

#include "src/Lightning/namespace/lightning.hpp"
#include <stdint.h>

/*!
 * @brief Hash represents fast comparison of
 * two strings using CRC32 algorithm
 */
class lightning::Hash
{
public:
	static uint32_t crc32gen(const char *);

	static bool crc32cmp(const char*, const char*);
};

#endif // __HASH_H
