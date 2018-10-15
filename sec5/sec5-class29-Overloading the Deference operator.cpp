// Overloading the Deference operator

/*
	Ejercicio:

*/

/*
	Notas:
	Vamos a implementar en el operador * la operación conjugado de los números enteros. Este operador devolverá un número complejo nuevo, por lo que usaremos un constructor. Este número será igual que el original, salvo que el signo de la parte imaginaria será el opuesto.

	Hay que tener en cuenta la preferencia de operadores. En el caso de la expresión '*c1 + *Complex(4, 3)', los operadores * tienen prioridad frente al
*/

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace caveofprogramming;

int main() {

	Complex c1(3, 2);
	cout << *c1 + *Complex(4, 3) << endl;

	return 0;
}