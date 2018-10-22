/*
	Ejercicio:


	Notas:
	Cuando tenemos una expresión lambda y capturamos una variable por valor, por defecto no podemos modificarla. Si lo hacemos, daría un error de compilación. Para poder modificar las variables que capturemos por valor, tenemos que poner la palabra clave 'mutable' entre los paréntesis y las llaves: '[var]() mutable {var = bla}'. Adedmás, hay que tener en cuenta que el valor de la variable original no se cambia.

*/

#include <iostream>

using namespace std;


int main() {

	int cats = 5;

	[cats]() {
		cats = 8;
		// imprime 8
		cout << cats << endl;
	}();

	// imprime 5
	cout << cats << endl;

	return 0;
}