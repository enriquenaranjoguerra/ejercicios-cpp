// Making classes iterable

/*
	Ejercicio:
	Crear una clase con una subclase iterador que implemente todo lo necesario para recorrer los elementos.	

	Notas:
	Hasta ahora teníamos la clase ring que era bastante similar a un vector o lista, pero para iterar teníamos que usar un índice. Lo idóneo sería iterar con un bucle for mejorado tal como 'for (string value: textring) {}'. O si tuviéramos que iterar mediante un iterador, necesitaríamos que tuviera los métodos 'begin' y 'end', además de los operadores '!=', '++' y '*' sobrecargados.

	Si hacemos que el bucle con iterador funcione, el bucle mejorado funcionará también.

	Hay que destacar que aunque iterator es una clase amiga de ring por ser subclase, en principio no tiene forma de acceder a los elementos privados de ring. Por esto, tenemos que pasar de algún modo una referencia a la clase ring en los métodos begin y end.

*/

#include <iostream>
#include "ring.h"

using namespace std;

int main() {

	ring<string> textring(3);
	textring.add("one");
	textring.add("two");
	textring.add("three");
	// El cuarto elemento debería sobrescribir el primero
	// textring.add("four");


	// for (ring<string>::iterator it = textring.begin(), it != textring.end(); it++) {
	for (auto it = textring.begin(), it != textring.end(); it++) {
		cout << *it << endl;
	}

	cout << endl;
	for (auto value : textring) {
		cout << value << endl;
	}


	ring<string>::iterator it;
	it.print();

	return 0;
}