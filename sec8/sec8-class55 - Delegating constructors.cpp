/*
	Ejercicio:


	Notas:
	Cuando creamos una instancia de una clase hija, llamamos a los constructores de las clases padre porque los constructores no se heredan. Si creamos un constructor con parámetros, perderemos el constructor por defecto, y si no se lo especificamos, el hijo no sabrá dónde tiene que llamar.

	Para ello, en el constructor hijo escribimos el constructor padre como una variable: 'Hijo(paramHijo) : Padre(paramPadre) {}'.

	En C++ 98 no se podía llamar desde un constructor a otro, pero en C++ 11 sí se puede. De nuevo, basta con introducirlo con dos puntos, como hemos hecho antes: 'Clase() : Clase(param) {}' sería el constructor sin argumentos llamando al constructor con un argumento 'param'. Esto se llama 'delegación de constructores'.

	Hay que tener cuidado de que dos constructores no se llamen entre sí para evitar crear un bucle.
	
	Esta delegación de constructores es distinta al constructor por defecto, por lo que no podemos usarlo con la palabra 'default'.
*/

#include <iostream>

using namespace std;

class Parent {
	int dogs{5};
	string text;
public:
	Parent(){
		cout << "No parameter parent constructor" << endl;
	}

	Parent(string text) {
		this->text = text;
		cout << "string parent constructor" << endl;
	}
};

class Child : public Parent {
public:
	Child() = default;
	Child(): Parent("Hello") {

	}
};

int main() {

	Parent parent("Hello") ;
	Child child;




	return 0;
}