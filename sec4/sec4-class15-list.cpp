/* 
	Ejercicio:
	- Reimplementar el ejemplo utilizando un bucle while en vez de un bucle for, para que quede más "elegante".

	- Crear un menú para que el usuario elija si insertar o eliminar un elemento y luego muestre la lista.
*/

/*
	Notas: list and vectors

	En los vectores, todos los elementos están almacenados uno a continuación del otro. Por esto, solo se pueden insertar elementos al final de un vector, pero el acceso a elementos es más rápido.

	En las listas, cada elemento está contenido en un nodo, que apunta al elemento siguiente y al anterior (lista doblemente enlazada). La ventaja de las listas es poder insertar números al final, principio o en cualquier posición. También podemos eliminar elementos de la lista.

	Para insertar números al final, igual que con vectores, se usa el método push_back. Para insertar números al principio, se usa el método push_front.

	Para insertar elementos en la posición n, necesitamos tener un iterador previamente y utilizar el método insert(iterador, valor).

	Para eliminar elementos de la lista, usamos el método erase(iterador). Esto eliminará el nodo de la lista, lo cual hará que el iterador no sea de confianza. La zona de memoria a la que apunta el iterador del elemento eliminado puede haber sido reutilizada o no, por lo que mostrar el resultado por al consola con *iterador no sabemos qué puede pasar. Para solucionar esto, basta con asignar a la variable iterador el iterador que devuelve el método erase, que será otro iterador sin el elemento eliminado.

*/

#include <iostream>
#include <list>
using namespace std;

template<class T>
void iterateOverList(list<T> lista){
	auto it = lista.begin();
	// He tenido que utilizar 'auto' porque no sé qué tipo de variable es it
	while(it != lista.end()){
		cout << *it++ << endl;
	}
}

int main(){

	list<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	cout << "Iterando con 'while'..." << endl;
	list<int>::iterator itForInsert = numbers.begin();
	itForInsert++;
	numbers.insert(itForInsert, 100);
	cout << "Hemos insertado el 100: " << endl;
	iterateOverList(numbers);

	list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	eraseIt = numbers.erase(eraseIt);
	cout << "Hemos eliminado el 100: " << endl;
	iterateOverList(numbers);

	cout << "Iterando con 'for'..." << endl;
	for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << endl;
	}

	return 0;
}

