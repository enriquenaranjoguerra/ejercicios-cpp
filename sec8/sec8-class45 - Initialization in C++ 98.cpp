// Inicialization in C++ 98

/*
	Ejercicio:


	Notas:
	Podemos usar las llaves para inicializar objetos de distinto tipo. Por ejemplo, podemos iniciar un array  sin especificar el tamaño y especificando los objetos que lo componen entre llaves (ejemplo values).

	Si una clase o estructura tiene un miembro 'text' de tipo string y un miembro 'id' de tipo int públicos, se pueden inicializar mediante {"texto", 7} (ejemplos C y S).

	También podemos declarar variables justo después de la llave que cierra una clase o estructura e instanciar el objeto como antes (ejemplo R). En este caso ni siquiera es necesario el nombre de la clase o estructura en caso de que no tengamos pensado usarla de nuevo. Además, podemos tener una lista separada por comas de objetos.

	Sin embargo, el alcance de esto es limitado y en cuanto queremos aplicarlo a un vector, nos damos cuenta de que no se puede.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int values[] = {1, 4, 5};
	cout << values[0] << endl;
	cout << endl;

	class C {
	public:
		string text;
		int id;
	};
	C c1 = {"Hello", 7};
	cout << c1.text << endl;
	cout << endl;

	struct S {
		string text;
		int id;
	};
	S s1 = {"Hello", 7};
	cout << s1.text << endl;
	cout << endl;

	struct R {
		string text;
		int id;
	} r1 = {"Hello", 7}, r2 = {"Hi", 9};
	cout << r1.text << endl;
	cout << r2.text << endl;
	cout << endl;

	vector<string> strings;
	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	return 0;
}