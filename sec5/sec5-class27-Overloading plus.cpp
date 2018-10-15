// Overloading plus

/*
	Notas:
	Para sobrecargar el operador '+', tenemos varias opciones. La primera es hacerlo un miembro de la clase, pero también podemos hacerlo incluso más encapsulado creando una función separada como hemos hecho con la sobrecarga del operador '<<'. Esto podemos hacerlo aprovechando que tenemos unos getter y que al sumar dos valores, dichos valores no cambian, solo devolveremos su suma (por el tema del 'const').

	También es posible que queramos sumar un número complejo con algo que no es un número complejo, por ejemplo, un número real que representaremos por un double. Lo que haremos será añadir el double a la parte real del complejo.

	Si solo implemento el operador + con la cabecera 'Complex operator+(const Complex &c1, double d)', en la suma tendré que poner el double en el lado derecho del operador +.
*/

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace caveofprogramming;



int main() {

	Complex c1(3, 4);
	cout << c1 << endl;

	Complex c2(2, 3);
	cout << c1 + c2 << endl;

	Complex c3 = c1 + c2;
	cout << c1 + c2 + c3 << endl;

	Complex c4(4, 2);
	Complex c5 = c4 + 7;
	cout << c5 << endl;

	cout << 7 + c1 + c2 + 8 + 9 + c6 << endl;


	return 0;
}