// Object Initialization, Default and Delete

/*
	Ejercicio:
	Crear una clase propia y comprobar que las palabras 'default' y 'delete' funcionan.

	Notas:
	Podemos inicializar los miembros de una clase con valores por defecto simplemente indicando el valor que queremos que tengan cuando se inicialice el objeto. Si quisiéramos darles otros valores, necesitaríamos métodos o constructores. Pero si usamos constructores, podemos perder el constructor vacío por defecto.

	C++ 11 nos permite recuperar el constructor vacío por defecto mediante la palabra clave 'default'. De este modo no necesitamos tener unas llaves vacías. Igualmente pasa con el constructor copia. En resumen, la palabra 'default' nos devuelve la implementación por defecto de algún elemento, como el constructor vacío o copia o el operador =. Esto será útil cuando hayamos perdido estas implementaciones por defecto.

	Ahora supongamos que no queremos que el objeto sea copiable. Necesitaríamos una forma de eliminar implementaciones por defecto. Para ello, usaremos la palabra reservada 'delete'.
*/

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Test {
	int id{3}; // int id = 3;
	string name{"Mike"};

public:
	Test() = default; // recuperamos el constructor vacío

/*	Test(const Test &other) = default; // innecesario porque no hemos implementado otro constructor copia
	Test &operator=(const Test &other) = default; // innecesario porque no hemos implementado otro operador '='
*/

	Test(const Test &other) = delete; // eliminamos el constructor copia
	Test &operator=(const Test &other) = delete; // eliminamos el operador '='

	public Test(int id) : id(id) {
	}

	void print() {
		cout << id << ": " << name << endl;
	}
};


int main() {

	Test test;
	test.print();

	Test test1(77);
	test1.print();

//	Test test2 = test1; // inicialización copia -> necesitamos el constructor copia
//	test2 = test; // asignación -> necesitamos el operador '='

	return 0;
}