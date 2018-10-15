// Overloading assignment operator

/* 
	Ejercicio:
	Crear una clase propia e implementarle el operador '=' y el constructor copia.
*/

/*
	Notas:
	Cuando escribimos test2 = test1, c++ utiliza un mecanismo por defecto para el operador de
	asignación '='. Muchas veces este mecanismo copia hace justo lo que queremos, pero otras veces
	no lo hará. Por ejemplo, si el 'id' es un identificador, querremos que sea único para cada
	instancia de la clase. Por otro lado, usando punteros, crearías un puntero apuntando a la zona
	de memoria de test1 en vez de crear tu propia copia.

	Llamar al operador '=', sería similar a llamar a un método. Es decir, 'test2 = test1' <=>
	'test2.metodo(test1)'. Además, cuando llamamos a un método de la forma 'test2.metodo(test1)',
	estamos pasando un primer argumento que es un puntero al objeto 'test2', lo que nos permite usar
	la palabra 'this'.

	También podemos pensar en cadenas de llamadas de tipo 'test3 = test2 = test1'. Por esto, podemos
	considerar que el tipo de retorno del método '=' no sería void, sino una referencia al objeto que
	está llamando al método.

	Un caso curioso es cuando declaramos e inicializamos la variable en la misma línea, como hacemos
	con 'Test test4 = test1'. En este caso, no se llama al operador '=', sino al constructor copia.

	Por tanto, si implementamos el operador '=', deberíamos implementar también el constructor copia.
	Así evitamos que se llame a uno u otro sin darnos cuenta.


	
*/

#include <iostream>

using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test() : id(0), name("") {
	}
	Test(int id, string name) : id(id), name(name) {
	}
	Test(const Test &other) {
		cout << "Copy constructor running" << endl;
		id = other.id;
		name = other.name;
	}
	void print(){
		cout << id << ": " << name << endl;
	}

	const Test &operator=(const Test &other){

		cout << "Assignment running" << endl;
		id = other.id;
		name = other.name;

		return *this;
	}
};

int main(){

	Test test1(10, "Mike");
	cout << "Print test1: " << flush;
	test1.print();

	Test test2(20, "Bob");
	test2 = test1;
	cout << "Print test2: " << flush;
	test2.print();

	Test test3;
//	test3 = test2 = test1;

	test3.operator=(test2); // equivalente a 'test3 = test2'
	cout << "Print test3: " << flush;
	test3.print();

	cout << endl;
	// Copy initialization
	Test test4 = test1;
	cout << "Print test4: " << flush;
	test4.print();

	return 0;
}