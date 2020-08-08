#include "src/Lightning/Line/line.hpp"
#include "src/Lightning/Regex/regex.hpp"
#include "src/Lightning/Hash/crc8.hpp"
#include "src/Lightning/Hash/crc16.hpp"
#include "src/Lightning/Hash/crc32.hpp"
#include "src/Lightning/Hash/sha256.hpp"
#include "src/Lightning/Math/math.hpp"
#include "src/Lightning/Complex/complex.hpp"
#include "src/defines.hpp"
#include <iostream>

using lightning::Line;
using lightning::Regex;
using lightning::SHA256;
using lightning::CRC8;
using lightning::CRC16;
using lightning::CRC32;
using lightning::Math;
using lightning::Complex;
using std::cout;
using std::endl;

int main(void)
{
#ifdef	__START_TIME
		__START_TIME
#endif
#ifdef	__DEBUG_LINE
	Line a = "std::ios::sync_with_stdio(false))))))123";
	Line b = a;
	std::cout << "first string: \t\t\t\t" << a << std::endl;
	std::cout << "length of first string: \t\t" << a.length() << std::endl;
	std::cout << "reverse first string: \t\t\t" << a.reverse() << std::endl;
//	std::cout << "cut \" \" from first string: \t\t" << a.cut(" ") << std::endl;		// [!!!] BUG
//	std::cout << "replace \":\" with \".\": \t\t\t" << a.replace(":", ".") << std::endl;
	std::cout << "convert first string to uppercase: \t" << a.to_upper() << std::endl;
	std::cout << "convert first string to lowercase: \t" << a.to_lower() << std::endl;
	std::cout << "concatenate first string with \"[0-9]+\":\t" << a + " [0-9]+" << std::endl;
	std::cout << "concatenate first string with itself: \t" << a + a << std::endl;
	std::cout << "clear first string: \t" << a.clear()	<< std::endl;
	std::cout << "first string == itself: \t\t" << (a == a) << std::endl;
	std::cout << "first string != itself: \t\t" << (a != a) << std::endl;
	std::cout << "first string == \"123\": \t\t\t" << (a == "123") << std::endl;
	std::cout << "first string != \"123\": \t\t\t" << (a != "123") << std::endl;
	std::cout << "match text (regex): \t\t\t" << Regex::match_exists(".*false", a.to_char_array()) << std::endl;
#endif//__DEBUG_LINE
#ifdef	__DEBUG_REGEX
	regex pattern = "[0] !//[regular expression]";
	std::cout << regex::regex_find(pattern, "\\S+\\s\\S+\\s\\S+") << std::endl;
#endif//__DEBUG_REGEX
#ifdef  __DEBUG_HASH
#define ARR_SIZE 10
#define TEXT 0
#define HASH 1

//////////////////////
//CHECK HASH OF STRING
//////////////////////
	const char* sha256_values[ARR_SIZE][2] =
	{
		{
			"C++",
			"f1deb75fa21d3c47a6e7a45967b79fad2d053947066dc95322c5bcee1e9fe21c"
		},
		{
			"sha256",
			"5d5b09f6dcb2d53a5fffc60c4ac0d55fabdf556069d6631545f42aa6e3500f2e"
		},
		{
			"test",
			"9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08"
		},
		{
			"This tool allows you to generate the SHA256 hash of any string.",
			"d6ec3b0f68b9a5127b9b3fe4b130c5d446dfd82c819d068f76834d146270b1fc"
		},
		{
			"PHP",
			"0a6a15345ad0c7e36ed9dc3ec9c8ce843af4bc765d1019eb6d563e0836b962f3"
		},
		{
			"Python",
			"18885f27b5af9012df19e496460f9294d5ab76128824c6f993787004f6d9a7db"
		},
		{
			"Lua",
			"b897ce727082286d99b851bcc54df589cf3704f56d3cc76e8b389e7f336e5735"
		},
		{
			"CoffeeScript",
			"99500c7189ab3d7565bacd906cb0c46607b898096cfdef814b3ccce269c21a20"
		},
		{
			"C#",
			"040228846ead4a4195145fe089343cb0894d00a9380176a41a8f6c5ee70b4824"
		},
		{
			"Perl",
			"eca37636c0711d96f605f252e43a4f3d0811a2ce7495c004b43eea2a9f7216e8"
		}
	};

	for (int i = 0; i < ARR_SIZE; i++) {
		SHA256 sha;
		sha.update(sha256_values[i][TEXT]);
		uint8_t* digest = sha.digest();
		char hash[65];
		SHA256::to_string(hash, digest);
		std::cout << sha256_values[i][TEXT] << std::endl;
		std::cout << "[0] generated key: " << hash << std::endl;
		std::cout << "[1] original key:  " << sha256_values[i][HASH] << std::endl;
		if (SHA256::hashcmp(hash, sha256_values[i][HASH])) {
			std::cout << "SUCCESS" << std::endl;
		} else {
			std::cout << "FAILURE" << std::endl;
		}
		std::cout << std::endl;
	}
//////////////////////
//CHECK HASH OF FILE
//////////////////////
//	SHA256 sha;
//	const char* file = "/home/machen/CODE/C++/test/sha256.hpp";
//	sha.update(SHA256::read_from_file(file));
//	char hash[65];
//	uint8_t* digest = sha.digest();
//	SHA256::to_string(hash, digest);
//	printf("FILE sha256.hpp=       %s\n", hash);
//	printf("original hash:         %s\n", "2b8c9e341eea724c02b291404533d44bb5fb4028d97a5c452b9bcd9bef008225");
//////////////////////
//CHECK CRC{8..32} OF STRING
//////////////////////
//	const char* string = "crc is a very simple algorithm";
//	printf("CRC-8: \t\t%x\n",		CRC8::crc8gen(string));
//	printf("CRC-16: \t%x\n",		CRC16::crc16gen(string));
//	printf("CRC-32: \t%lx\n",		CRC32::crc32gen(string));
//	printf("CRC-8 compare: \t%d\n",	CRC8::crc8cmp(string, "crc is a very simple algorithm"));
//	printf("CRC-16 compare: %d\n",	CRC16::crc16cmp(string, "crc is a very simple algorithm"));
//	printf("CRC-32 compare: %d\n",	CRC32::crc32cmp(string, "crc is a very simple algorithm"));
#endif//__DEBUG_HASH
#ifdef __DEBUG_MATH
	cout <<"Math::squareRoot<float>(8192): ";
	cout << Math::squareRoot<float>(8192) << endl;
	cout <<"Math::power<float>(2.1, 10): ";
	cout << Math::power<float>(2.1, 10) << endl;
	cout <<"Math::squareRoot<float>('d'): ";
	cout << Math::squareRoot<float>('d') << endl;
	cout <<"Math::max((Math::power<int>(2, 10)), Math::squareRoot<int>(81)): ";
	cout << Math::max((Math::power<int>(2, 10)),
					   Math::squareRoot<int>(81)) << endl;
	cout <<"Math::min((Math::power<int>(2, 10)), Math::squareRoot<int>(81)): ";
	cout << Math::min((Math::power<int>(2, 10)),
					   Math::squareRoot<int>(81)) << endl;
	cout <<"Math::roundUp<float>(2.3): ";
	cout << Math::roundUp<float>(2.3) << endl;
	cout <<"Math::roundDown<float>(2.923)";
	cout << Math::roundDown<float>(2.923) << endl;
	cout << endl;
	Complex<float> complex(123, 3);
	Complex<float> complex2(12, 100);
	cout << "(123 + 3) + (12 + 100) = ";
	cout << complex + complex2 << endl;
	cout << "(123 + 3) - (12 + 100) = ";
	cout << complex - complex2 << endl;
	cout << "(123 + 3) / (12 + 100) = ";
	cout << complex / complex2 << endl;
	cout << "(123 + 3) * (12 + 100) = ";
	cout << complex * complex2 << endl;
#endif//__DEBUG_MATH
#ifdef	__FINISHED_AT
		__FINISHED_AT
#endif
	return EXIT_SUCCESS;
}
