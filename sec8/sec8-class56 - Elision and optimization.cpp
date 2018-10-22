/*
	Ejercicio:


	Notas:
	Supongamos que tenemos una clase con varios constructores y una función 'getTest' que devuelve un objeto del tipo de esta clase. Si llamamos a la función 'getTest' en la función main, normalmente se crearía el objeto, lo imprimiríamos y luego se destruiría. Si quitásemos la bandera de 'optimización', pasa el infierno.

	En C++ las expresiones normalmente se resuelven de derecha a izquierda. Así que lo que pasa es que en 'getTest' llamamos a un constructor, con lo que creamos una instancia del objeto. Para devolver el objeto, tenemos que copiarlo en el valor de retorno, por eso saltaría el constructor copia. Después saltaría el destructor de la variable creada dentro de la función 'getTest'.

	Una vez fuera de la función, hay que copiar el valor de 'return' en la variable 'test1'. Esto sucede porque cuando declaramos e inicializamos una variable, no usamos el operador asignación, sino el constructor copia. Una vez copiado el objeto, hay que destruir la copia temporal de 'return'. Luego vemos el objeto impreso por la pantalla y el destructor que se llama al final de la función 'main'.

	Queríamos crear una variable a partir de un objeto y al final hemos creado 3 instancias del mismo, lo cual es tremendamente ineficiente.

	C++ 11 puede hacer optimización de valores de retorno, que básicamente es deshacerse de todas estas copias inútiles.

	En vectores, también podemos perder mucha eficiencia si no tenemos cuiadado. Si hacemos 'vector.push_back(Test())', estaremos creando un objeto Test y luego copiándolo dentro del vector en la posición adecuada. C++ 11 resuelve esto mediante referencias y asignaciones de movimiento.


*/

#include <iostream>
#include <vector>

using namespace std;

class Test {
	int i;
public:
	Test() {
		cout << "Constructor" << endl;
	}
	Test(int i) {
		cout << "Parametrized constructor" << endl;
	}
	Test(const Test &other) {
		cout << "Copy constructor" << endl;
	}
	Test &operator=(const Test &other) {
		cout << "Assignment" << endl;
		return *this;
	}
	~Test() {
		cout << "Destructor" << endl;
	}
	friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
	out << "Hello from test";
	return out;
}

Test getTest() {
	return Test();
}

int main() {

	Test test1 = getTest();
	cout << test1 << endl;

	vector<Test> vec;
	vec.push_back(Test());



	return 0;
}