/*
	Ejercicio:
	- Crea un menú que permita almacenar información en un mapa, editarla o eliminarla. También que permita
	buscar un valor en un mapa. Y que mostrar el mapa completo sea una opción. Además, que los valores sean
	una clase 'Persona' creada por nosotros.
	- Crear un tipo más complejo, como mapas de vectores o mapas de mapas.
*/

/*
	Notas: maps
	Conjunto de clave-valor. Se crean con 'map<keyType, valueType>' introducen los valores con 'map[key]=value'.

	Las claves son únicas, así que si escribimos 'map[key]=value' para una clave que ya existe, se actualiza su
	valor.

	Si tratamos de acceder a una clave que no existe, se creará con el valor 0 (null) por defecto en el mapa.

	Para comprobar si una clave está en el mapa o no, se usa el método 'find(clave)'. Este método devuelve un
	iterador apuntando al elemento si existe, si no, apunta al final del mapa.

	Podemos usar el concepto de 'pair' bien para introducir elementos en el mapa con el método
	'insert(pair<key, value>)' o bien para iterar con un iterador mediante
	'pair<key, value> nombreDelPar = *iterador'. Además, la función 'make_pair' crea un par del tipo apropiado y
	lo devuelve, con lo que podemos insertarlo en el mapa.


*/

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> ages;

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;

	ages["Mike"] = 70;

	//ages.insert(pair<string, int>("Peter", 100));
	ages.insert(make_pair("Peter", 100));

	cout << ages["Raj"] << endl;

	if (ages.find("Vicky") != ages.end()) {
		cout << "Found Vicky" << endl;
	} else {
		cout << "Key not found" << endl;
	}

	cout << "Iterar sobre las claves:" << endl;
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << "Iterar sobre los pares:" << endl;
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		pair<string, int> age = *it;
		cout << age.first << ": " << age.second << endl;
	}

	return 0;
}

