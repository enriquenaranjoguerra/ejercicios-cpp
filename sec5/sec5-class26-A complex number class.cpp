// A complex number class

/* 
	Ejercicio:

*/

/*
	Notas:
	Vemos cómo funcionan las cabeceras y las implementaciones. Para esta sección necesitaremos dos ficheros auxiliares, Complex.h y Complex.cpp. El fichero Complex.h contendrá la cabecera (similar a la firma en Java) de los métodos. Por otro lado, el fichero Complex.cpp incluirá la implementación de los métodos. La excepción puede ser en métodos cortos, cuya implementación puede ir directamente en el mismo fichero Complex.h.

	Cuando un método se marca como 'const' o marcamos alguno de los atributos como 'const', tenemos que asegurarnos de que todos los métodos que llamemos por el camino van a ser también 'const'. Esto es porque 'const' supone un contrato por el que no vamos a modificar un objeto y, en tiempo de compilación, debemos asegurarnos que así sea.
*/

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace caveofprogramming;



int main(){

	Complex c1(2, 3);
	Complex c2(c1); // copy initialization
	c1 = c2; // assignment operator

	Complex c3 = c2; // copy initialization

	cout << c2 << " " << c3 << endl;

	return 0;
}