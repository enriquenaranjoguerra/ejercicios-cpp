#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include <string>
#include <cstdint>
using namespace std;

namespace caveofprogramming {

class Mandelbrot {
private:
public:
	static const int MAX_ITERATIONS = 1000;

public:
	Mandelbrot();
	virtual ~Mandelbrot();

	int static getIterations(double x, double y);

};

}

#endif /* MANDELBROT_H_ */