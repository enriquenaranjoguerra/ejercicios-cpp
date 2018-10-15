// Multimaps

/*
	Ejercicio:
	- Crear un multimapa y pintar todos los valores asociados a una clave.
*/

#include <iostream>
#include <map>
using namespace std;

void showAllValuesFromAKey(multimap<string, int> &alumnos, const string &key);

int main() {

	multimap<string, int> alumnos;

	alumnos.insert(make_pair("Paco", 1));
	alumnos.insert(make_pair("María", 2));
	alumnos.insert(make_pair("María", 3));
	alumnos.insert(make_pair("Carmen", 2));
	alumnos.insert(make_pair("Carmen", 3));
	alumnos.insert(make_pair("María", 1));
	alumnos.insert(make_pair("Carmen", 1));
	alumnos.insert(make_pair("Paco", 3));

	showAllValuesFromAKey(alumnos, "Paco");
	showAllValuesFromAKey(alumnos, "María");
	showAllValuesFromAKey(alumnos, "Carmen");

	return 0;
}

void showAllValuesFromAKey(multimap<string, int> &alumnos, const string &key) {
	auto its = alumnos.equal_range(key);

	for (auto it = its.first; it != its.second; it++) {
		cout << it->first << " ha sacado la nota: " << it->second << endl;
	}
}

