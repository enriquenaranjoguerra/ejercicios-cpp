// Custom objects as Map Values

/*
	Notas:
	El constructor por defecto se pierde cuando creamos otro constructor con parámetros. Podemos recuperar
	el constructor sin parámetros pasando valores por defecto.
	
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
	Person(const Person &other){
		cout << "Copy constructoy running!" << endl;
		name = other.name;
		age = other.age;
	}
	void print() {
		cout << name << ": " << age << endl;
	}
};

int main(){

	map<int, Person> people;

	people[0] = Person("Mike", 40);
	people[1] = Person("Vicky", 20);
	people[2] = Person("Raj", 30);

	people.insert(make_pair(55, Person("Bob", 45)));
	people.insert(make_pair(55, Person("Sue", 24)));
 
	for(map<int, Person>::iterator it = people.begin(); it != people.end(); it++){
		cout << it->first << ": " << flush;
		it->second.print();
	}

	return 0;
}

