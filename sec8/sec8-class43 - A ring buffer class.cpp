// A ring buffer class

/*
	Ejercicio:


	Notas:
	Nuestra clase anillo debe implementar los métodos add, size y get para que se comporten como esperaríamos de estructuras similares.

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
	textring.add("four");
	for (int i = 0; i < textring.size(); i++) {
		cout << textring.get(i) << endl;
	}


	ring<string>::iterator it;
	it.print();

	return 0;
}