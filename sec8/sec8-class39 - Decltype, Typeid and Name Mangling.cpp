// Decltype, Typeid and Name Mangling

/*
	Ejercicio:
	Hacer algo similar a esto.

	Notas:
	typeid es una función que nos devuelve un objeto con cierta información acerda del objeto que pasamos como argumento. Si queremos saber por ejemplo el nombre del tipo de objeto, lo haremos llamando al método 'name()'.

	Mientras en C solo tenemos funciones, en C++ tenemos métodos atados a objetos y sobrecarga de métodos, de modo que cada función necesita más información acerca del contexto. Por eso, cuando llamamos al método 'name()', obtenemos mucha más información además del nombre.

*/

#include <iostream>
#include <typeinfo>

using namespace std;

int main() {

	string value;
	cout << typeid(value).name() << endl;
	// Si el tipo es integer, sale 'i' por consola, indicando que es un integer. Si fuera un double saldría 'd'. Si el tipo es string, podríamos obtener 'Ss' o algo más feo dependiendo del compilador.

	// como value es de la clase string, escribir decltype(value) es lo mismo que esribir string para declarar una nueva variable.
	decltype(value) name = "Bob";
	cout << typeid(name).name() << endl;
	cout << name << endl;

	return 0;
}