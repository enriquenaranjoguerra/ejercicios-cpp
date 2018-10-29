/*
	Ejercicio:
	Probar asignar memoria a un objeto con un unique_ptr así como a un vector también con un unique_ptr.

	Notas:
	unique_ptr creará un puntero inteligente que se encarga de gestional la deslocalización de la memoria. Como es una clase plantilla, le pasaremos como parámetro la clase a la que apuntará el puntero. Dentro del constructor instanciaremos con 'new' al objeto al que apuntamos.

	Importante: necesitamos la cabecera 'memory', aunque la mayoría de cabeceras ya lo incluyen.

	Antes de C++11 teníamos auto_ptr, que es similar a unique_ptr, pero ahora está desactualizado.

	Una pega del unique_ptr es que no funciona con arrays tal cual. Hay que acceder al objeto en cuestión y entonces invocar el método que queramos.

*/

#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
	Test() {
		cout << "created" << endl;
	}
	void greet() {
		cout << "Hello" << endl;
	}
	~Test() {
		cout << "destroyed" << endl;
	}
};

class Temp {
private:
	unique_ptr<Test[]> pTest;
public:
	Temp() : pTest(new Test[2]) {

	}
};

int main() {

	{
		unique_ptr<Test> pTest(new Test);
		pTest->greet();
	}

	cout << endl;

	{
		unique_ptr<Test[]> pTest(new Test[2]);
		pTest[1].greet();
	}

	Temp temp;

	cout << "finished" << endl;

	return 0;
}