// Range-based loop

/*
	Ejercicio:
	Probar este tipo de bucles.

	Notas:
	El bucle for mejorado (enhanced) nos permite recorrer todos los valores de un array, vector, etc. Se declara como 'for(tipo var : array)', donde en tipo pondremos normalmente 'auto' para que el compilador detecte qué tipo de variable necesita. En cada iteración, podremos usar el objeto 'var' para hacer lo que haríamos con un bucle 'for' normal en la iteración 'array[i]'.

	Incluso si hiciera falta usar un iterador para recorrer una lista, al menos podríamos usar la palabra clave 'auto' para ahorrarnos la declaración del iterador: 'for(vector<int>::iterator it = numbers.begin())' pasaría a ser 'for(auto it = numbers.begin())'.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

	auto texts = {"one", "two", "three"};

	for (auto text : texts) {
		cout << text << endl;
	}

	// Aquí no usamos auto porque queremos que numbers sea un vector
	vector<int> numbers;
	numbers.push_back(5);
	numbers.push_back(7);
	numbers.push_back(9);
	numbers.push_back(11);

	for (auto number : numbers) {
		cout << number << endl;
	}

	string hello = "Hello";
	for (auto c : hello) {
		cout << c << endl;
	}


	return 0;
}