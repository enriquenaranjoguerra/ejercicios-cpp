// Decltype, Typeid and Name Mangling

/*
	Notas:
	La palabra 'auto' permite al compilador inferenciar el tipo de variable a partir de la declaración. Esto sirve especialmente cuando la declaración es muy larga, como pasaba con los iteradores.

	También podemos usar 'auto' para el tipo de retorno de funciones. En este caso, debemos escribir una flecha '->' después del nombre de la función y el tipo de objeto de retorno que esperamos. Esto sin más no tiene mucha utilidad, ya que podríamos poner 'int' en vez de 'auto' en el tipo de retorno y escribir menos.

	La utilidad viene con las funciones plantilla. Si 'test' es una función plantilla con parámetro T, podemos declarar el tipo de retorno usando la palabra clave 'decltype' como vimos anteriormente. Podemos hacerlo también, por ejemplo, con dos parámetros sumados entre sí. O si una función 'f' llama a otra función 'g', podemos escribir 'decltype(g())' en 'f'.

	Por tanto, si estamos inicializando una variable, salvo que queramos poner el tipo concreto, podemos usar la palabra 'auto'. Lo mismo para funciones y el tipo de retorno, pero apoyándonos en el decltype.

*/

#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>
auto test(T value) -> decltype(value) {
	return value;
}

template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2) {
	return value1 + value2;
}

int get() {
	return 999;
}


auto test2() -> decltype(get()) {
	return get();
}

int main() {

	auto value = 7;
	auto text = "Hello";
	cout << value << endl;
	cout << text << endl;

	cout << endl;
	cout << "Test function:" << endl;
	cout << test("Hello there") << endl;
	cout << test(5 + 6) << endl;

	cout << endl;
	cout << "Test 2 function:" << endl;
	cout << test2() << endl;


	return 0;
}