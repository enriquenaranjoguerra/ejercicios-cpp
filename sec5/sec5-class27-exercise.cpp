// Overloading plus

/*
	Ejercicio:
	Probar implementando la función + como un miembro de la clase ComplexIn.
*/

#include <iostream>
#include "ComplexIn.h"

using namespace std;
using namespace caveofprogramming;

int main() {

	ComplexIn c1(3, 4);
	cout << c1 << endl;

	ComplexIn c2(2, 3);
	cout << c1 + c2 << endl;

	ComplexIn c3 = c1 + c2;
	cout << c1 + c2 + c3 << endl;

	ComplexIn c4(4, 2);
	ComplexIn c5 = c4 + 7;
	cout << c5 << endl;

	cout << 7 + c1 + c2 + 8 + 9 + c6 << endl;

	return 0;
}