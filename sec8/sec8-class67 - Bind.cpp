/*
	Ejercicio:
	Probar bind con funciones sin argumentos, con argumentos hardcodeados, con placeholders y mezclándolos. Probar también la palabra 'function' y con métodos. Si me veo con ganas, ver cómo hacer bind a métodos estáticos.

	Notas:
	Bind sirve para definir funciones para unos parámetros fijos dados o bien para parámetros que nosotros le pasemos. En este segundo caso, tendríamos que enumerar los parámetros del 1 en adelante con un guión bajo delante. A estos parámetros se les llama 'placeholders'. La razón por la que están estos números precedidos de un guión bajo, es que el orden de los argumentos puede cambiarse. Lo que ponga donde esté el _1 irá al primer argumento.

	Igualmente se puede usar bind para métodos de una clase. Para ello, escribiremos 'bind(Clase::metodo, &instancia, params...)'.

*/

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test{
public:
	int add(int a, int b, int c) {
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}
};

int run(function<int(int, int)> func) {
	func(7, 3);
}

int main() {

	cout << add(1, 2, 3) << endl;

	Test test;
	auto calculate = bind(&Test::add, &test, _1, _2, _3); //& es para pasar la instancia por referencia, no por valor, y así evitar copiarla.
	cout << calculate(10, 20, 30) << endl;
	// Esto es lo mismo que la orden anterior, independientemente de lo que haya dentro de la función add.
	// auto calculator = bind(add, _2, _1, _3);
	// cout << calculate(20, 10, 30) << endl;

	// Esto imprimiría 20, 10 y 30.
	// auto calculator = bind(add, _2, _1, _3);
	// cout << calculate(10, 20, 30) << endl;

	// Ahora el segundo argumento siempre es un 100, por lo que calculate acepta 2 argumentos en vez de 3
	// auto calculator = bind(add, _2, 100, _1);
	// cout << calculate(10, 20) << endl;

	cout << run(calculate) << endl;

	return 0;
}