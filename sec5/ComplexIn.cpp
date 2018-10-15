/*
 * ComplexIn.h
 *
 */

#include "ComplexIn.h"

namespace caveofprogramming {



class ComplexIn {
private:
	double real;
	double imaginary;
public:
	ComplexIn::ComplexIn() : real(0), imaginary(0) {
	};
	ComplexIn::ComplexIn(double real, double imaginary) : real(real), imaginary(imaginary) {
	};
	ComplexIn::ComplexIn(const ComplexIn &other) {
		cout << "Copying" << endl;
		real = other.real;
		imaginary = other.imaginary;
	}
	const ComplexIn &ComplexIn::operator=(const ComplexIn &other) {
		real = other.real;
		imaginary = other.imaginary;

		return *this;
	}

	bool ComplexIn::operator==(const ComplexIn &other) {
		return (real == other.real) && (imaginary == other.imaginary);
	}

	bool ComplexIn::operator!=(const ComplexIn &other) {
		return !(*this == other);
		// también podemos escribir (real != other.real) || (imaginary != other.imaginary)
	}

	ComplexIn ComplexIn::operator*() const {
		return ComplexIn(real, -imaginary);
	}

	ostream ComplexIn::&operator<<(const ComplexIn &number) {
		cout << "(" << number.getReal() << ", " << number.getImaginary() << ")";
		return cout;
	}

	ComplexIn ComplexIn::operator+(const ComplexIn &c1, const ComplexIn &c2) {
		return ComplexIn(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
	}

	ComplexIn ComplexIn::operator+(const ComplexIn &c1, double d) {
		return ComplexIn(c1.getReal() + d, c1.getImaginary());
	}
	ComplexIn ComplexIn::operator+(double d, const ComplexIn &c1) {
		return d + c1;
	}
};
} /* namespace caveofprogramming */
