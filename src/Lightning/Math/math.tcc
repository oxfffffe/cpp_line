#include "math.hpp"

using lightning::Math;

template<typename T>
auto Math::max(const T expr1, const T expr2) -> T {
	return expr1 > expr2 ? expr1 : expr2;
}

template<typename T>
auto Math::min(const T expr1, const T expr2) -> T {
	return expr1 < expr2 ? expr1 : expr2;
}

template<typename T>
auto Math::roundDown(const T expr) -> T {
	return (int)expr;
}

template<typename T>
auto Math::roundUp(const T expr) -> T {
	if (expr == (int)expr) {
		return expr;
	} else {
		return (int)expr + 1;
	}
}

template<typename T>
auto Math::squareRoot(const T expr) -> T {
	float x = expr;
	float y = 1;
	while (x - y > 0.000001) {
		x = (x + y) / 2;
		y = expr / x;
	}
	return x;
}

template<typename T>
auto Math::power(const T expr, const short extent) -> T {
	short step = 0;
	T result = 1;
	while (step++ < extent) {
		result *= expr;
	}
	return result;
}
