/* 
	Ejercicio:
	Crear un vector de dos dimensiones e inicializarlo con la tabla del 12
*/

/*
	Notas: vectors

	En los vectores, todos los elementos están almacenados uno a continuación del otro. Por esto, solo se pueden insertar elementos al final de un vector, pero el acceso a elementos es más rápido.

	Para insertar números se usa el método push_back.

	Para iterar, podemos hacerlo con el clásico bucle for o bien utilzar un iterador. Un iterador se instancia mediante vector<string>::iterator nombreDelIterador y cada elemento es un puntero a un elemento del vector (o lista) asociado. De modo que si queremos acceder al valor del vector, tenemos que usar el operador sobrecargado de indirección *.

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

//	vector < vector <int> > grid(3, vector<int>(4, 7));
//	grid[1].push_back(8);
//	for (int row = 0; row < grid.size(); row++) {
//		for(int col = 0; col < grid[row].size(); col++) {
//			cout << grid[row][col] << flush;
//		}
//		cout << endl;
//	}

	vector < vector <int> > tablaDel12(2, vector<int>(5, 12));
	int i = 1;
	for (int row = 0; row < tablaDel12.size(); row++) {
		for(int col = 0; col < tablaDel12[row].size(); col++){
			tablaDel12[row][col] *= i++;
		}
	}

	for (int row = 0; row < tablaDel12.size(); row++) {
		for(int col = 0; col < tablaDel12[row].size(); col++){
			cout << tablaDel12[row][col] << "  ";
			if((col + 1) % 5 == 0){
				cout << endl;
			}
		}
	}

	return 0;
}
