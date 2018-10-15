// Function pointers

/*
	Ejercicio:
	Crear una función que tome dos parámetros y devuelva algo que no sea void. Crear un puntero a esa función y llamar a la función a través del puntero.
*/

#include <iostream>

using namespace std;

double suma(double n, double m) {
	return n + m;
}

int main() {
	cout << "Suma normal: " << suma(1, 3) << endl;
	double (*pSuma)(double, double) = suma;
	cout << "Suma putero: " << pSuma(1, 3) << endl;

	return 0;
}