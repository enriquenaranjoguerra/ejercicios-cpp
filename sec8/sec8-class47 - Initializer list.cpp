// Initializer list

/*
	Ejercicio:
	Volver al objeto ring que implementamos hace varios tutoriales y reformatearlo para que use la initializer_list. Añadir un método que permita añadir o editar valores en el anillo.

	Notas:
	initializer_list nos va a permitir usar una expresión de tipo '{bla1, bla2, ..., blaN}' en el constructor o un método a modo de parámetro.

*/

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Test {
public:
	Test(initializer_list<strings> texts) {
		for (auto value : texts) {
			cout << value << endl;
		}
	}

	void print(initializer_list<strings> texts) {
		for (auto value : texts) {
			cout << value << endl;
		}
	}
};

int main() {

	vector<string> numbers = {1, 2, 4, 6};
	cout << strings[2] << endl;
	cout << endl;

	Test test{"apple", "orange", "banana"};
	cout << endl;

	test.print({"one", "two", "three", "four"});

	return 0;
}