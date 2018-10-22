/*
	Ejercicio:
	Probar los elementos vistos.

	Notas:
	¿Qué pasa si queremos usar una de las variables locales dentro de una expresión lambda? Hasta donde sabemos ahora, esto no es posible porque las expresiones lambda tienen su propio alcance (scope). Para esto, tenemos que capturar las variables locales entre los corchetes.

	Según cómo capturemos estas variables, se hará por valor o referencia, varias o todas.

*/

#include <iostream>

using namespace std;

int main() {

	int one = 1;
	int two = 2;
	int three = 3;

	// Capture one and two by value
	[one, two](){
		cout << one << ", " << two << endl;
	}();
	cout << endl;
	// Capture all local variables by value
	[=](){
		cout << one << ", " << two << ", " << three << endl;
	}();
	cout << endl;

	// Capture all local variables by value except three, by reference
	[=, &three](){
		// two = 7 da error porque two se ha pasado por valor
		three = 7;
		cout << one << ", " << two << ", " << three << endl;
	}();
	cout << three << endl;
	cout << endl;

	// Capture local variables all by reference
	[&](){
		two = 8;
		three = 7;
		cout << one << ", " << two << ", " << three << endl;
	}();
	cout << two << endl;
	cout << three << endl;
	cout << endl;

	// Capture local variables all by reference, but two and three
	[&, two, three](){
		one = 8;
		cout << one << ", " << two << ", " << three << endl;
	}();
	cout << one << endl;
	cout << three << endl;
	cout << endl;



	return 0;
}