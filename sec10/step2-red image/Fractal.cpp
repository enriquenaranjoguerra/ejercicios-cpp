#include <iostream>

#include "Bitmap.h"


using namespace std;


int main() {

	int const WIDTH = 800;
	int const HEIGHT = 600;


	Bitmap bitmap(WIDTH, HEIGHT);

	/* El origenl de coordenadas es la esquina inferior izquierda */
	bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 255, 255, 255); //centro de la imagen
	bitmap.setPixel(WIDTH / 2, 100, 255, 255, 255); // tirando hacia abajo

	// Colorear todo de rojo
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; y < WIDTH; x++) {
			bitmap.setPixel(x, y, 255, 0, 0);
		}
	}

	bitmap.write("test.bmp");

	cout << "Finished" << endl;

	return 0;
}