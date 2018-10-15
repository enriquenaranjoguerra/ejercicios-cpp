/* Ejercicio
	Crear un vector con algunos elementos e iterarlo con el for normal y con el iterator
*/

#include <iostream>
#include <vector>
using namespace std;


//int main(){
//
//	vector<string> strings;
//
//	strings.push_back("one");
//	strings.push_back("two");
//	strings.push_back("three");
//
//	// iterate
//	for (int i = 0; i < strings.size(); ++i) {
//		cout << strings[i] << endl;
//	}
//	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
//		cout << *it << endl;
//	}
//	return 0;
//}


int main() {

	vector<string> listaDeIngredientes;
	listaDeIngredientes.push_back("pan");
	listaDeIngredientes.push_back("tomate");
	listaDeIngredientes.push_back("aceite");
	listaDeIngredientes.push_back("jamón");

	cout << "Para un buen desayuno hace falta lo siguiente:" << endl;
	for (int i = 0; i < listaDeIngredientes.size(); i++) {
		cout << "· " << listaDeIngredientes[i] << endl;
	}

	cout << "También podemos preparar un salmorejo con los siguientes ingredientes:" << endl;
	for (vector<string>::iterator it = listaDeIngredientes.begin(); it != listaDeIngredientes.end(); it++) {
		if (*it != "jamón") {
			cout << "- " << *it << endl;
		}
	}

	return 0;
}