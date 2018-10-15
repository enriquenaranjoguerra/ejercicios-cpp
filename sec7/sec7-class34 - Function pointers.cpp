// Function pointers

/*
	Ejercicio:
	Crear una función que tome dos parámetros y devuelva algo que no sea void. Crear un puntero a esa función y llamar a la función a través del puntero.


	Notas:
	Igual que podemos declarar punteros a variables, podemos declarar punteros a funciones.

	Cuando creamos un puntero a una función, no necesitamos el nombre de esa función, sino el tipo de retorno (o void). Después del tipo, tendríamos un asterisco seguido del nombre de la variable y entre paréntesis. A continuación, pondríamos entre paréntesis los parámetros, si los hubiera.

	Para asignar a una variable de tipo puntero a función, escribimos el nombre de la función sin los paréntesis, ya que si los escribimos, estaríamos llamando a la función. Nosotros no queremos llamar a la función, solo queremos asignarla a la variable. En este paso, podemos escribir el operador & antes del nombre de la variable para hacer referencia a la dirección de esa variable, aunque no es necesario. Esto es porque el nombre de la función es de hecho un puntero a esa función.

	Para llamar a la función, tenemos que asegurarnos de que el operador de indirección * se aplica al nombre de la variable antes de que actúe el operador (). Pero en realidad no es necesario ni el operador de indirección ni por tanto los paréntesis, basta con poner el nombre del puntero seguido de paréntesis para invocar la función.

	Las variables de tipo puntero a función se pueden inicializar a la vez que se declaran. En el ejemplo de abajo, se escribiría 'void (*pTest)() = test'.
*/

#include <iostream>

using namespace std;

void test() {
	cout << "Hello" << endl;
}

void test(int val) {
	cout << "Hello: " << val << endl;
}

int main() {
	test();

	void (*pTest)();
	pTest = &test; // sin paréntesis, solo asignar, no llamar

	//llamada a la función
	(*pTest)();
	pTest();

	void (*pTest1)(int);
	pTest1 = test;
	test(3);
	pTest1(2);

	return 0;
}