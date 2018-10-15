// Set

/* 
	Ejercicio:
	Nada más empezar el vídeo, crear nuestro propio conjunto de una clase definida y probar
	las funcionalidades similares a las anteriores.
*/

/*
	Notas:
*/

#include <iostream>
#include <set>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person(string name, int age) :
		name(name), age(age) {
	}
	Person() :
		name(""), age(0) {
	}
	Person(const Person &other){
		name = other.name;
		age = other.age;
	}
	bool operator< (const Person &other) const {
		if(name == other.name){
			return age < other.age;
		}
		return name < other.name;
	}
	void printPerson(){
		cout << "This person is " << name << " and the age is " << age << endl;
	}
};

void showAllElements(set<Person> &people){
	for(auto person : people){
		person.printPerson();
	}
	cout << "Tenemos esta cantidad de personas: " << people.size() << endl;
	cout << endl;
}

int main(){

	set<Person> people;

	people.insert(Person("Juan", 25));
	people.insert(Person("Paco", 25));
	people.insert(Person("Marta", 25));
	people.insert(Person("Eva", 25));

	showAllElements(people);

	people.insert(Person("Juan", 40));

	showAllElements(people);

	people.insert(Person("Juan", 40));

	showAllElements(people);



	return 0;
}