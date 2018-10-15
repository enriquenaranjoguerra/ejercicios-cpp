/* Ejercicio
	Nada
*/


/*
	El método clear elimina todos los elementos del vector
	numbers.clear();

	El método resize modifica el tamaño (size) del vector

	El método reserve modifica la capacidad del vector. Si n es menor que la capacidad
	Si n es menor que la capacidad actual, el método no hace nada. Si es mayor, crea
	una nueva zona de memoria y mueve el vector allí.

	Diferencia entre size y capacity: size es la cantidad de elementos que tiene el vector.
	Capacity es la cantidad de elementos que se pueden almacenar en la zona de memoria antes
	de que esta esté llena. Si eso pasa, habrá que recolocar el vector en una zona de memoria
	mayor.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

	vector<int> numbers(0);
	cout << "Size: " << numbers.size() << endl;
	int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	for (int i = 0; i < 10000; ++i) {
		if(numbers.capacity() != capacity){
			capacity = numbers.capacity;
			cout << "Capacity: " << capacity << endl;
		}
		numbers.push_back(i);
	}

	return 0;
}
