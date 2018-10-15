/*
 * Complex.h
 *
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

 #include <iostream>
 using namespace std;

namespace caveofprogramming{

ostream &operator<<(ostream &out, const Complex &number);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

class Complex {
private:
	double real;
	double imaginary;
public:
	Complex(double real, double imaginary);
	Complex() : real(0), imaginary(0);
	Complex(const Complex &other);

	const Complex &operator=(const Complex &other){
		real = other.real;
		imaginary = other.imaginary;
	}

	double getReal() const { return real; }
	double getImaginary() const { return imaginary; }

	bool operator==(const Complex &other);
	bool operator!=(const Complex &other);
	Complex operator*() const;

};

} /* namespace caveofprogramming */

#endif /* COMPLEX_H_ */