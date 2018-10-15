/*
 * Complex.h
 *
 */

#ifndef "Complex.h"

namespace caveofprogramming{

ostream &operator<<(const Complex &number){
	cout << "(" << number.getReal() << ", " << number.getImaginary() << ")";
	return cout;
}

Complex operator+(const Complex &c1, const Complex &c2){
	return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex &c1, double d){
	return Complex(c1.getReal() + d, c1.getImaginary());
}
Complex operator+(double d, const Complex &c1){
	return d + c1;
}

class Complex {
private:
	double real;
	double imaginary;
public:
	Complex::Complex() : real(0), imaginary(0){
	};
	Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary){
	};
	Complex::Complex(const Complex &other){
		cout << "Copying" << endl;
		real = other.real;
		imaginary = other.imaginary;
	}
	const Complex &Complex::operator=(const Complex &other){
		real = other.real;
		imaginary = other.imaginary;

		return *this;
	}

	bool Complex::operator==(const Complex &other){
		return (real == other.real) && (imaginary == other.imaginary);
	}

	bool Complex::operator!=(const Complex &other){
		return !(*this==other);
		// también podemos escribir (real != other.real) || (imaginary != other.imaginary)
	}

	Complex Complex::operator*() const{
		return Complex(real, -imaginary);
	}

};
} /* namespace caveofprogramming */
