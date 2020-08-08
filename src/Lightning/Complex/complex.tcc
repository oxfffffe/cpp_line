#include "src/Lightning/Complex/complex.hpp"

using lightning::Complex;
using std::ostream;

template<typename T>
Complex<T>::Complex(T m_real, T m_image) {
	real = m_real;
	image = m_image;
}

template<typename T>
Complex<T>& Complex<T>::operator+=(const Complex<T>& rhs) {
	this->real += rhs.real;
	this->image += rhs.image;
	return *this;
}

template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T>& rhs) {
	return Complex<T>(*this) += rhs;
}

template<typename T>
Complex<T>& Complex<T>::operator-=(const Complex<T>& rhs) {
	this->real -= rhs.real;
	this->image -= rhs.image;
	return *this;
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex<T>& rhs) {
	return Complex<T>(*this) -= rhs;
}

template<typename T>
Complex<T>& Complex<T>::operator*=(const Complex<T>& rhs) {
	T resReal  = (this->real * rhs.real) - (this->image * rhs.image);
	T resImage = (this->image * rhs.real) + (this->real * rhs.image);
	real = resReal;
	image = resImage;
	return *this;
}

template<typename T>
Complex<T> Complex<T>::operator*(const Complex<T>& rhs) {
	return Complex<T>(*this) *= rhs;
}

template<typename T>
Complex<T>& Complex<T>::operator/=(const Complex<T>& rhs) {
	T resReal  =  (((this->real * rhs.real) + (this->image * rhs.image)) /
                     ((rhs.real * rhs.real) + (rhs.image * rhs.image)));
	T resImage = (((this->image * rhs.real) - (this->real * rhs.image)) /
                     ((rhs.real * rhs.real) + (rhs.image * rhs.image)));
	real = resReal;
	image = resImage;
	return *this;
}

template<typename T>
Complex<T> Complex<T>::operator/(const Complex<T>& rhs) {
	return Complex<T>(*this) /= rhs;
}
