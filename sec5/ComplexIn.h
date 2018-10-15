/*
 * ComplexIn.h
 *
 */

#ifndef COMPLEXIN_H_
#define COMPLEXIN_H_

#include <iostream>
using namespace std;

namespace caveofprogramming {



class ComplexIn {
private:
	double real;
	double imaginary;
public:
	ComplexIn(double real, double imaginary);
	ComplexIn() : real(0), imaginary(0);
		ComplexIn(const ComplexIn & other);
		const ComplexIn & operator=(const ComplexIn & other) {
		real = other.real;
		imaginary = other.imaginary;
	}

	double getReal() const { return real; }
	double getImaginary() const { return imaginary; }

	bool operator==(const ComplexIn &other);
	bool operator!=(const ComplexIn &other);
	ComplexIn operator*() const;

	ostream &operator<<(ostream &out, const ComplexIn &number);
	ComplexIn operator+(const ComplexIn &c1, const ComplexIn &c2);
	ComplexIn operator+(const ComplexIn &c1, double d);
	ComplexIn operator+(double d, const ComplexIn &c1);

};

} /* namespace caveofprogramming */

#endif /* COMPLEXIN_H_ */