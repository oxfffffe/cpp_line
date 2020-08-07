#include "sha256.hpp"

using lightning::SHA256;

#define watch(x)	\
	std::cout		\
	<< (#x)			\
	<< " is "		\
	<< "("			\
	<< (x)			\
	<< ")"			\
	<< std::endl
#define XOR ^
#define ROTR(x, y) (x >> y | x << (32 - y))
#define CHOOSE(e, f, g) ((e & f) XOR (~e & g))
#define MAJORITY(a, b, c) ((a & (b | c)) | (b & c))
#define SIG0(x) (ROTR(x, 7) XOR ROTR(x, 18) XOR (x >> 3))
#define SIG1(x) (ROTR(x, 17) XOR ROTR(x, 19) XOR (x >> 10))

SHA256::SHA256(){}

const uint32_t SHA256::SHA256_constants[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

uint32_t SHA256::states[8] =
{
	0x6a09e667,
	0xbb67ae85,
	0x3c6ef372,
	0xa54ff53a,
	0x510e527f,
	0x9b05688c,
	0x1f83d9ab,
	0x5be0cd19
};

uint32_t SHA256::blocklen = 0;

uint64_t SHA256::bitlen = 0;

void SHA256::update(const char* text) {
	states_reset();
	size_t index = 0;
	while (index < (size_t)strlen(text)) {
		data[blocklen++] = text[index];
		++index;
		if (blocklen == 64) {
			sha256gen();
			bitlen += 512;
			blocklen = 0;
		}
	}
}

uint8_t* SHA256::digest() {
	uint8_t* hash = new uint8_t[32];
	pad();
	revert(hash);
	return hash;
}

void SHA256::sha256gen() {
	uint32_t maj, xorA, ch, xorE, sum, newA, newE, m[64];
	uint32_t state[8];
	for (uint8_t i = 0, j = 0; i < 16; i++, j += 4) {
		m[i] = (data[j]     << 24) |
		       (data[j + 1] << 16) |
		       (data[j + 2] <<  8) |
		       (data[j + 3]);
	}
	for (uint8_t k = 16; k < 64; k++) {
		m[k] =  SIG1(m[k - 2])  +
		        SIG0(m[k - 15]) +
		        m[k - 7] +
		        m[k - 16];
	}
	for(uint8_t i = 0; i < 8; i++) {
		state[i] = states[i];
	}
	for (uint8_t i = 0; i < 64; i++) {
		xorA	 = ROTR(state[0], 2) XOR
		           ROTR(state[0], 13) XOR
		           ROTR(state[0], 22);
		xorE	 = ROTR(state[4], 6) XOR
		           ROTR(state[4], 11) XOR
		           ROTR(state[4], 25);
		ch       = CHOOSE  (state[4],
                            state[5],
                            state[6]);
		maj      = MAJORITY(state[0],
                            state[1],
                            state[2]);
		sum      = m[i] +
                   SHA256_constants[i] +
                   state[7] +
                   ch +
                   xorE;
		newA	 = xorA + maj + sum;
		newE	 = state[3] + sum;
		state[7] = state[6],
		state[6] = state[5],
		state[5] = state[4],
		state[4] = newE,
		state[3] = state[2],
		state[2] = state[1],
		state[1] = state[0],
		state[0] = newA;
	}
	for(uint8_t i = 0 ; i < 8 ; i++) {
		states[i] += state[i];
	}
}

void SHA256::pad() {
	uint64_t i = blocklen;
	uint8_t end;
	if (blocklen < 56) {
		end = 56;
	} else {
		end = 64;
	}
	data[i++] = 0x80;
	while (i < end) {
		data[i++] = 0;
	}
	if (blocklen >= 56) {
		sha256gen();
		memset(data, 0, 56);
	}
	bitlen  += blocklen * 8;
	data[63] = bitlen;
	data[62] = bitlen >> 8;
	data[61] = bitlen >> 16;
	data[60] = bitlen >> 24;
	data[59] = bitlen >> 32;
	data[58] = bitlen >> 40;
	data[57] = bitlen >> 48;
	data[56] = bitlen >> 56;
	sha256gen();
}

void SHA256::revert(uint8_t* hash) {
	for (uint8_t i = 0; i < 4; i++) {
		_mm_set_epi16 (
		 hash[i    ]  = (states[0] >> (24 - i * 8)) & 0x000000ff,
		 hash[i + 4]  = (states[1] >> (24 - i * 8)) & 0x000000ff,
		 hash[i + 8]  = (states[2] >> (24 - i * 8)) & 0x000000ff,
		 hash[i + 12] = (states[3] >> (24 - i * 8)) & 0x000000ff,
		 hash[i + 16] = (states[4] >> (24 - i * 8)) & 0x000000ff,
		 hash[i + 20] = (states[5] >> (24 - i * 8)) & 0x000000ff,
		 hash[i + 24] = (states[6] >> (24 - i * 8)) & 0x000000ff,
		 hash[i + 28] = (states[7] >> (24 - i * 8)) & 0x000000ff);
	}
}

void SHA256::to_string(char result[65], const uint8_t *digest) {
	for (size_t i = 0; i < 32; i++) {
		result += sprintf(result, "%02x", digest[i]);
	}
}

char* SHA256::read_from_file(const char* filename) {
	char* fcontent = NULL, c;
	uint64_t index = 0;
	uint64_t pagenum = 1;
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp) {
		while ((c = getc(fp)) != EOF) {
			if (!fcontent || index == 1024) {
				fcontent  = (char*)realloc(fcontent, 65535 * pagenum + 1);
				++pagenum;
			}
			fcontent[index++] = c;
		}
		fcontent[index] = '\0';
		fclose(fp);
	}
	return fcontent;
}

bool SHA256::hashcmp(char lhs[], const char rhs[]) {
	return CRC32::crc32cmp(lhs, rhs);
}

void SHA256::states_reset() {
	blocklen = 0;
	bitlen = 0;
	states[0] = 0x6a09e667;
	states[1] = 0xbb67ae85;
	states[2] = 0x3c6ef372;
	states[3] = 0xa54ff53a;
	states[4] = 0x510e527f;
	states[5] = 0x9b05688c;
	states[6] = 0x1f83d9ab;
	states[7] = 0x5be0cd19;
}

SHA256::~SHA256() { }
