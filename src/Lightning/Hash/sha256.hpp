#ifndef __SHA256_H
#define __SHA256_H

#include <x86intrin.h> ///<  SIMD
#include <stdint.h>    ///<  uint{8..64}_t
#include <stdio.h>	   ///<  sprintf
#include "src/Lightning/Hash/crc32.hpp" ///< SHA256::hashcmp
#include "src/Lightning/namespace/lightning.hpp" ///< strlen

/*!
 * @brief SHA256 algorithm implementation.
 */
class lightning::SHA256 {
public:
	SHA256();

	~SHA256();
	/*!
	 * @brief Copy input text to m_data.
	 * @param string to copy.
	 */
	void update(const char* data);
	/*!
	 * @brief Convert unsigned char array to string.
	 * @param SHA-256 key converted to array of uint8_t.
	 * @return Converted string.
	 */
	static void to_string(char result[65], const uint8_t* digest);
	/*!
	 * @brief Save generated hash to uint8_t variable.
	 * @return hash
	 */
	uint8_t* digest();
	/*!
	 * @brief Reset private values after previous time.
	 * @variable blocklen
	 * @variable bitlen
	 * @variable states[8]
	 */
	void states_reset();
	/*!
	 * @brief Read from file.
	 * @param Filename.
	 * @return File content as string.
	 */
	static char* read_from_file(const char* filename);
	/*!
	 * @brief Compare two hashes.
	 */
	static bool hashcmp(char lhs[], const char rhs[]);

private:
	/*!
	 * @brief Table with first 32 bits of
	 * the fractional parts of the cube roots of the
	 * first 64 primes [2..311]. (Wiki)
	 */
	static const uint32_t SHA256_constants[64];
	/*!
	 * @brief Char array to encrypt.
	 */
	uint8_t data[64];
	/*!
	 * @brief Length of m_data.
	 */
	static uint32_t blocklen;
	/*!
	 * @brief Count of bits in m_data.
	 */
	static uint64_t bitlen;
	/*!
	 * @brief Hash values.
	 */
	static uint32_t states[8];
	/*!
	 * @brief Generate hash.
	 */
	inline void sha256gen();

	inline void pad();
	/*!
	 * @brief Final setting of generated hash.
	 * @param Generated hash.
	 */
	inline void revert(uint8_t* hash);
};

#endif // __SHA256_H
