// Nested template clases

/*
	Ejercicio:


	Notas:
	Para este tutorial vamos a necesitar el concepto de buffer circular. Básicamente son zonas de memoria que se recorren y cuando se llega al final, en vez de terminar, se vuelve al principio.

	Podemos declarar una clase dentro de otra clase. Por ejemplo, 'iterator' dentro de la clase 'ring'. De este modo, para instanciar la clase iterator dentro de la clase ring debemos acceder mediante la sintaxis 'ring::iterator'. Sin embargo, aunque es una técnica frecuente, por lo general no se consideran buenas prácticas. La razón es que conforme ganamos profundidad, las cosas se vuelven feas, y no sabremos a dónde pertenecen los métodos, si a una clase padre o hija.

	Para evitar esto y seguir usando clases anidadas, dejaremos la declaración dentro de la clase y la implementación fuera. En el ejemplo, dentro de 'ring' tendríamos 'class iterator' y fuera, para indicar que 'iterator' es una subclase de 'ring', escribiríamos 'class ring::iterator { bla }'.

	Ahora queremos que la clase 'ring' sea plantilla y que la subclase 'iterator' pueda usar el parámetro que le pasamos. Para la clase 'ring', haríamos lo mismo que para cualquier clase plantilla, pero para la subclase iterator tenemos que escribir 'ring<T>::iterator' además del 'template<class T>' encima de la declaración de la clase.

*/

#include <iostream>
#include "ring.h"

using namespace std;

int main() {

	//ring<string> textring(3);
	//textring.add("one");
	//textring.add("two");
	//textring.add("three");
	//// El cuarto elemento debería sobrescribir el primero
	//textring.add("four");
	//for (int i = 0; i < textring.size(); i++) {
	//	cout << textring.get(i) << endl;
	//}

	/*
	output should be:
	four
	two
	three
	*/

	ring<string>::iterator it;
	it.print();

	return 0;
}