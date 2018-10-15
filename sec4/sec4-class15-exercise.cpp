/* 
	Ejercicio:

	- Crear un menú para que el usuario elija si insertar o eliminar un elemento y luego muestre la lista.
	- Crear una opción para guardar o cargar la lista de un archivo externo. Nota: no guardar la lista en
	sí, ya que es un puntero, sino guardar los valores.
*/

#include <iostream>
#include <list>
using namespace std;

template<class T>
void iterateOverList(list<T>* lista){
	auto it = lista->begin();
	int i = 1;
	while(it != lista->end()){
		cout << "Elemento número " << i++ << ": " << *it++ << endl;
	}
}

void startList(list<int>* numbers){
	numbers->clear();
	numbers->push_back(3);
	numbers->push_back(2);
	numbers->push_back(8);
	numbers->push_front(5);
}

int main(){

	list<int> numbers;
	startList(&numbers);

	int selection;
	char insertDelete;
	while(selection != 0){
		iterateOverList(&numbers);
		list<int>::iterator it = numbers.begin();
		cout << "Elige un elemento, 0 para salir o -1 para reiniciar" << endl;
		cin >> selection;
		if (selection == 0) {
			break;
		} else if (selection == -1) {
			startList(&numbers);
			continue;
		} else if (selection != 0 || selection != -1) {
			for(int j = 0; j < selection; j++){
				it++;
			}
		} else {
			cout << "Esa opción no es correcta: " << selection << endl;
			continue;
		} 
		cout << "Elige I para insertar o E para eliminar" << endl;
		cin >> insertDelete;
		if(insertDelete == 'I' || insertDelete == 'i'){
			cout << "Escribe el número que quieres insertar" << endl;
			int numberToInsert;
			cin >> numberToInsert;
			numbers.insert(it, numberToInsert);
		} else if (insertDelete == 'e' || insertDelete == 'e'){
			it = numbers.erase(it);
		} else {
			cout << "Esa opción no es correcta" << endl;
			continue;
		}
	}

	return 0;
}