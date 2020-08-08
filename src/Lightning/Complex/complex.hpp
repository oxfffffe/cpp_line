#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "src/Lightning/namespace/lightning.hpp"
#include <ostream>

template<typename T>
class lightning::Complex {
public:
	explicit Complex(T m_real, T m_image);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& out, const Complex<U>& expr) {
		return out << "(" << expr.real << " + " << expr.image << "i" << ")";
	}

	Complex<T>& operator+=(const Complex<T>&);

	Complex<T> operator+(const Complex<T>&);

	Complex<T>& operator-=(const Complex<T>&);

	Complex<T> operator-(const Complex<T>&);

	Complex<T>& operator*=(const Complex<T>&);

	Complex<T> operator*(const Complex<T>&);

	Complex<T>& operator/=(const Complex<T>&);

	Complex<T> operator/(const Complex<T>&);

private:
	T real;
	T image;
};

#include "complex.tcc"

#endif // COMPLEX_HPP
