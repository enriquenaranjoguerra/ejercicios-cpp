#include <iostream>

#include "Bitmap.h"


using namespace std;


int main() {

	int const WIDTH = 800;
	int const HEIGHT = 600;


	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = -999999;


	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; y < WIDTH; x++) {
			double xFractal = (x - WIDTH / 2) * 2.0 / WIDTH;
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			if (xFractal < min) {
				min = xFractal;
			}
			if (xFractal > max) {
				max = xFractal;
			}

			cout << min << "min, " max << endl;

			min = 999999;
			max = -999999;
			if (yFractal < min) {
				min = yFractal;
			}
			if (yFractal > max) {
				max = yFractal;
			}
		}
	}



	bitmap.write("test.bmp");

	cout << "Finished" << endl;

	return 0;
}