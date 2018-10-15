/*
	Ejercicio:
	- Crea un menú que permita almacenar información en un mapa, editarla o eliminarla. También que permita
	buscar un valor en un mapa. Y que mostrar el mapa completo sea una opción. Además, que los valores sean
	una clase 'Persona' creada por nosotros.
	- Crear un tipo más complejo, como mapas de vectores o mapas de mapas.
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
	Person();

	Person(string name, int age, string nationality) :
		name(name),
		age(age),
		nationality(nationality) {
	};

	Person(const Person &other) {
		cout << "Copy constructor running" << endl;
		name = other.name;
		age = other.age;
		nationality = other.nationality;
	}

	string getPersonData();
	void setPersonData(string, int, string);
private:
	string name;
	int age;
	string nationality;
};

void Person::setPersonData(string name, int age, string nationality) {
	this->name = name;
	this->age = age;
	this->nationality = nationality;
}

string Person::getPersonData() {
	return (name + "-" + to_string(age) + "-" + nationality);
}

map<int, Person> people;
char option;
string data;

void initMap() {
	people.clear();
	people.insert(make_pair(1, Person("Mike", 40, "American")));
	people.insert(make_pair(2, Person("Raj", 20, "English")));
	people.insert(make_pair(3, Person("Vicky", 30, "Scotish")));
	people.insert(make_pair(4, Person("Vicky", 30, "Scotish")));
}

int getFirstFreeId() {
	int matchedId = 0;
	for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
		if ((it->first) == (matchedId - 1)) {
			matchedId++;
		} else {
			return (it->first);
		}
	}
	return matchedId;
}

int enterUserId() {
	cout << "Escribe el número identificador del usuario" << endl;
	int userId;
	cin >> userId;
	if (option == 'E' || option == 'A') {
		cout << "Introduce nombre, edad y nacionalidad separados por guión" << endl;
		cin >> data;
	}
	return userId;
}

void showUsers() {
	for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
		cout << "Id: " << it->first << ", datos de la persona: " << it->second.getPersonData() << endl;
	}
}

vector<string> splitString(string* cadena) {
	vector<string> divided;
	string delimiter = "-";
	size_t pos = 0;
	string token;
	while ((pos = cadena->find(delimiter)) != string::npos) {
		token = cadena->substr(0, pos);
		divided.push_back(token);
		cadena->erase(0, pos + delimiter.length());
	}
	return divided;
}

void editUser(int userId, string* data) {
	vector<string> datos = splitString(data);
	people[userId].setPersonData(datos[0], atoi(datos[1].c_str()), datos[2]);
}

void addUser(int userId, string* data) {
	vector<string> datos = splitString(data);
	int id = getFirstFreeId();
	people.insert(make_pair(id, Person(datos[0], atoi(datos[1].c_str()), datos[2])));
}

void deleteUser(int userId) {
	for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
		if (it->first == userId) {
			people.erase(it);
			break;
		}
	}
}

int main() {
	initMap();

	while (option != 'S' || option != 's') {
		cout << "Elige una opción" << endl;
		cout << "M: muestra los usuarios" << endl;
		cout << "E: edita un usuario" << endl;
		cout << "A: añade un usuario" << endl;
		cout << "Q: elimina un usuario" << endl;
		cout << "S: salir" << endl;
		cin >> option;
		option = toupper(option);

		if (option == 'S') {
			break;
		}

		int userId;

		switch (option) {
		case 'M':
			showUsers();
			break;
		case 'E':
			userId = enterUserId();
			editUser(userId, &data);
			break;
		case 'A':
			userId = enterUserId();
			addUser(userId, &data);
			break;
		case 'Q':
			userId = enterUserId();
			deleteUser(userId);
			break;
		}
	}

	return 0;
}