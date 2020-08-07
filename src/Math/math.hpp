#ifndef MATH_HPP
#define MATH_HPP

#include "src/Lightning/namespace/lightning.hpp"

class lightning::Math {
public:
	template<typename T>
	static auto max(const T expr1, const T expr2) -> T;

	template<typename T>
	static auto min(const T expr1, const T expr2) -> T;

	template<typename T>
	static auto roundDown(const T expr) -> T;

	template<typename T>
	static auto roundUp(const T expr) -> T;

	template<typename T>
	static auto squareRoot(const T expr) -> T;

	template<typename T>
	static auto power(const T expr, const short extent) -> T;
};

#include "math.tcc"

#endif // MATH_HPP
