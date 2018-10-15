// Custom objects as Map Keys

/*
	Notas:
	c++ por defecto no sabe cómo comparar objetos de una clase propia, como la clase 'Person'. Por esto, tenemos que sobrecagar el operador '<'. La sobrecarga de un operador es equivalente a crear un método con firma 'person1.lessThan(person2)'.

	Para sobrecargar un operador escribimos el tipo de retorno, la palabra clave 'operator', el operador que queremos sobrecargar, entre paréntesis los parámetros del método (que será una	referencia a otro objeto del mismo tipo con la palabra clave 'const') y antes de las llaves, la palabra const de nuevo para asegurar que el método no va a cambiar el valor de nada. Las dos palabras const sirven para no modificar ni el objeto que
	pasa para comparar ni el propio objeto con el que se está comparando.

	Si añadimos un par nuevo con un objeto existente como clave, se actualizará el valor. Lo que se entiende como "mismo objeto" dependerá del operador sobrecargado '<'. El objeto que se usa como clave no se actualiza. Es posible que c++ considere iguales dos objetos que en realidad no lo son. Si '<' solo compara nombres pero no edades, Mike de 40 años y Mike de 50 años serán la misma persona.
*/

#include <iostream>
#include <map>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person(): name(""), age(0) {

	}
	Person(string name, int age) :
		name(name), age(age) {
	}
	Person(const Person &other) {
		name = other.name;
		age = other.age;
	}
	void print() const {
		cout << name << ": " << flush;
	}
	bool operator<(const Person &other) const {
		if (name == other.name) {
			return age < other.age;
		}
		return name < other.name;
	}
};

int main() {

	map<Person, int> people;

	people[Person("Mike", 40)] = 40;
	people[Person("Mike", 444)] = 123;
	people[Person("Vicky", 20)] = 20;
	people[Person("Raj", 30)] = 30;


	for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
		cout << it->second << ": " << flush;
		it->first.print();
		cout << endl;
	}

	return 0;
}

