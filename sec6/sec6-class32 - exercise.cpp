// Template functions

/*
	Ejercicio:
	Crear un programa donde poner el tipo o no conlleve a un comportamiento diferente. Pista: podemos sobrecargar funciones que se comporten distinto según el argumento que estemos pasándole.
*/

#include <iostream>

using namespace std;

template<typename T>
T getItBack(T t){
	return t;
}

void print(int n){
	cout << "Esto es un entero: " << n << endl;
}

void print(double d){
	cout << "Esto es un double: " << d << endl;
}

int main() {

	print(getItBack(5));
	print(getItBack<double>(5));

	return 0;
}