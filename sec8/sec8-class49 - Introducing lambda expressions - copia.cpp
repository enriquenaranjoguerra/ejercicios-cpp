// Introducing lambda expressions

/*
	Ejercicio:
	Define una expresión lambda simple y prueba a llamarla directamente o a través de una función, asignada y sin asignar a una variable.

	Notas:
	Una expresión lambda empieza por '[]', continúa con unos paréntesis '()' y termina con unas llaves '{}'. Representan funciones sin nombre cuyo código va entre llaves. Podemos almacenar estas funciones sin nombre dentro de un puntero declarando 'auto func = lambda_expression'. Mejor no preguntar ese 'auto' qué es.

	Si asignamos la expresión lambda a una variable, podemos llamarla desde un puntero de función. Basta con crear una función de este tipo y pasarle como parámetro la variable que contiene nuestra expresión lambda. Incluso podemos pasarle la expresión directamente.
*/

#include <iostream>

using namespace std;

void test(void (*pFunc)(/*sin parámetros*/)){
	pFunc();
}

int main() {

	auto func = []() {
		cout << "Hello" << endl;
	};

	func(); // imprime "Hello"
	// '[]() { cout << "Hello" << endl; }();' el mismo resultado
	test(func);
	test([]() { cout << "Hello" << endl; });

	return 0;
}