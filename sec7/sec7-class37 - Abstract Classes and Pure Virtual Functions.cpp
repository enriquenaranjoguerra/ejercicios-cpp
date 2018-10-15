// Abstract Classes and Pure Virtual Functions

/*
	Notas:
	A veces vamos a tener varias clases que derivan de una clase común, pero esta clase no tiene sentido instanciarla. Un ejemplo podría ser que Perro, Gato o Girafa derivan de la clase Animal, pero no tiene sentido instanciar la clase Animal, ya que siempre sabremos que el animal es de una clase concreta.

	Para esto existen las clases abstractas y los métodos virtuales puros. Estos métodos no tienen implementación. Sigiendo con el ejemplo, podemos decir que todos los animales 'hablan' en el sentido de que cada uno emite algún tipo de sonido, pero no podemos decir que un 'animal' emita un sonido concreto. Pero cuando Perro hereda de Animal, su sonido en inglés es 'woof', que será el sonido que emita. Para decir que el método 'speak' es virtual puro escribiremos en la cabecera 'virtual void speak() = 0'. Este '= 0' significa que el método no tiene implementación. Una clase que contenga métodos puros virtuales será una clase abstracta, como lo es por ejemplo Animal.

	Además de esto, si una clase abstracta tiene n métodos virtuales puros y una de sus subclases no los implementa todos, esta subclase también será abstracta. Eso podría servir, por ejemplo, si después de la clase Perro necesitásemos otra clase hija Carlino que termine de implementar ciertos métodos que no puede implementar cualquier Perro.

	Otra razón para hacer todo esto, y es por contrato. Cualquier clase que herede de una clase abstracta y quiera ser instanciada tiene que implementar los métodos. Además, no se permite instanciar las clases abstractas también por contrato.

	Otro uso es crear un array de 'punteros' a animales (no de animales en sí, porque necesitaríamos un constructor e instanciarlos). Pero a la hora de pasar la referencia de estos punteros, tienen que ser clases concretas con todos los métodos implementados, como la clase Labrador. De modo similar, podemos crear una función que acepte como parámetro cualquier animal y pasarle una clase concreta como Labrador. Dado que cualquier animal corre, Labrador tendrá implementado el método correr, por lo que podemos invocar dicho método.

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