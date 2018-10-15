// Sorting vectors, Deque and Friend

/*
	Notas:
	std incluye un método 'sort' para vectores. Para poder llamar a este método, es necesario que
	la clase que contiene el vector tenga sobrecargado el operador '<' para poder darle orden.

	Otra forma de abordar el orden es utilizar un comparador (necesitamos la cabecera algorithm).
	Para ello creamos una función a la que llamaremos 'comparator(Clase &a, Clase &b)' y se la
	pasamos a la función 'sort' mediante 'sort(vector.begin(), vector.end(), comparator)'. Cabe
	destacar que aquí 'comparator' es un puntero a una función a la que nos referimos por su nombre.

	Otro problema que surge es que si desde la función 'comparator' intentamos acceder a los valores
	de la variable sin más, nos dará un error, ya que las variables en las clases son privadas salvo
	que se especifique lo contrario.

	Para esto sirve la palabra reservada 'friend'. Si cogemos la firma de la función y la colocamos
	dentro de la clase precedida de la palabra 'friend', esta función podrá acceder a los miembros
	privados de la clase.

	La función 'sort' es poco eficiente, y por tanto, si queremos un vector ordenado quizás
	deberíamos considerar utilizar un 'set' o alguna estructura que ordene automáticamente.

	La clase Deque (abreviación de double queue) del STD es similar a un vector con dos diferencias.
	Se pueden añadir y sacar elementos al principio y al final del deque (métodos 'push_back', 'push_front'
	'pop_back' y 'pop_front'), a cambio de perder eficiecia a la hora de iterar sobre él.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
private:
	int id;
	string name;
public:
	Test(int id, string name) :
		id(id), name(name) {
	}
	void print() {
		cout << id << ": " << name << endl;
	}

	/*
	bool operator<(const Test &other) const {
		return name < other.name;
	}
	*/

	friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b) {
	return a.name < b.name;
}

int main() {

	vector<Test> tests;

	tests.push_back(Test(5, "Mike"));
	tests.push_back(Test(10, "Sue"));
	tests.push_back(Test(7, "Raj"));
	tests.push_back(Test(3, "Vicky"));

	sort(tests.begin(), tests.end(), comp);

	for (int i = 0; i < tests.size(); i++) {
		tests[i].print();
	}

	return 0;
}