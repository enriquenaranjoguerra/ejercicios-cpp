// Multimaps

/*
	Notas:
	Multimap es un mapa que permite tener claves repetidas.

	Si queremos extraer todos los pares de una sola clave, tenemos que crear un par de iteradores
	de tipo 'pair<multimap<key, value>::iterator, multimap<key, value>::iterator> its =
	nuestroMultimapa.equal_range(claveRepetida)'. Luego haremos un bucle 'for' en el que
	instanciaremos un iterador 'it' mediante 'it = its.first' y la condición de finalización será
	'its.second'.

	Al declarar el par de iteradores, tenemos tonedas de 'boilerplate code'. C++ 11 introduce la
	palabra clave 'auto', que hace que el compilador fije el tipo de variable en función de lo
	que venga del otro lado del igual.
*/

#include <iostream>
#include <map>
using namespace std;


int main() {

	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vicky"));
	lookup.insert(make_pair(30, "Raj"));
	lookup.insert(make_pair(20, "Bob"));

	for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	for (multimap<int, string>::iterator it = lookup.find(10); it != lookup.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its =
	    lookup.equal_range(30);
	for (multimap<int, string>::iterator it = its.first; it != its.second; it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	auto its2 = lookup.equal_range(30);
	for (multimap<int, string>::iterator it = its2.first; it != its2.second; it++) {
		cout << it->first << ": " << it->second << endl;
	}

	return 0;
}

