#include "math.hpp"

using lightning::Math;

template<typename T>
auto Math::fabs(const T expr) noexcept -> T {
	return expr < 0 ? -expr : expr;
}

template<typename T>
auto Math::max(const T expr1, const T expr2) noexcept -> T {
	return expr1 > expr2 ? expr1 : expr2;
}

template<typename T>
auto Math::min(const T expr1, const T expr2) noexcept -> T {
	return expr1 < expr2 ? expr1 : expr2;
}

template<typename T>
auto Math::roundDown(const T expr) noexcept -> T {
	return (int)expr;
}

template<typename T>
auto Math::roundUp(const T expr) noexcept -> T {
	if (expr == (int)expr) {
		return expr;
	} else {
		return (int)expr + 1;
	}
}

template<typename T>
auto Math::squareRoot(const T expr) noexcept -> T {
	float x = expr;
	float y = 1;
	while (x - y > 0.000001) {
		x = (x + y) / 2;
		y = expr / x;
	}
	return x;
}

template<typename T>
auto Math::power(const T expr, const short extent) noexcept -> T {
	short step = 0;
	T result = 1;
	while (step++ < extent) {
		result *= expr;
	}
	return result;
}

template<typename T>
auto Math::sin(const T expr) noexcept -> T
{
	double cur  = expr;
	double pow  = expr;
	double acc  = 1;
	double fact = 1;
	int i = 1;
	while (fabs(acc) > 0.000001 && i < 100) {
		fact *= (2 * i) * (2 * i + 1);
		pow  *= -Math::power(expr, 2);
		acc   = pow / fact;
		cur  += acc;
		i++;
	}
	return cur;
}

template<typename T>
auto Math::cos(const T expr) noexcept -> T {
	return Math::sin(expr + 3.14159265 / 2);
}

template<typename T>
auto Math::tg(const T expr) noexcept -> T {
	return sin(expr) / cos(expr);
}

template<typename T>
auto Math::ctg(const T expr) noexcept -> T {
	return cos(expr) / sin(expr);
}
