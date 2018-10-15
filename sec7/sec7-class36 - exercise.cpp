// Abstract Classes and Pure Virtual Functions

/*
	Ejercicio:
	Crear una jerarquía de clases de dos o tres clases. Verifica que no se puede instanciar una clase abstracta. Verifica que tampoco se puede instanciar una clase heredera si no ha implementado todos los métodos virtuales puros. Crear también un array de punteros a una super clase.

	Vehículo -> todo lo de abajo
	Coche -> número de ruedas
	Toyota -> país origen
	Yaris -> consumo
*/

#include <iostream>

using namespace std;

class Animal {
public:
	virtual void run() = 0;
	virtual void speak() = 0;
};

class Dog: public Animal {
public:
	virtual void speak(){
		cout << "Woof!" << endl;
	}
};

class Labrador : public Dog {
public:
	Labrador() {
		cout << "new labrador" << endl;
	}
	virtual void run(){
		cout << "Labrador running" << endl;
	}
};

void test(Animal &a){
	a.run();
}

int main() {

	// Esto daría problemas, ya que Animal es una clase abstracta
	// Animal animal;

	// Esto no da problemas porque perro no es una clase abstracta mientras no exista el método run()
	// Dog dog;
	// dog.speak();

	Labrador lab;
	lab.run();
	lab.speak();

	Animal *animals[5];
	animals[0] = &lab;

	cout << "Array of animals:" << endl;
	animals[0]->speak();

	cout << "Test function with animals" << endl;
	test(lab);


	return 0;
}