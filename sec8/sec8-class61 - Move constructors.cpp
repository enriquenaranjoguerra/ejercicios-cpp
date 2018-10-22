/*
	Ejercicio:
	

	Notas:
 	En un 'move constructor', tendremos como parámetro un objeto temporal, un RValue, y querremos robarle los recursos a ese objeto.

 	En nuestro ejemplo de la clase test, el problema viene cuando robamos el puntero _pBuffer al hacer esto: '_pBuffer = other._pBuffer;'. Concretamente, el problema viene con el destructor del objeto 'other'. Querremos desasignar la memoria asignada al puntero en 'other', pero este es nulo, y desasignar memoria de un objeto nulo solo trae lágrimas y dolor.

 	Por eso, la solución consiste en que antes de salir del constructor, le asignemos al puntero el valor 'nullptr' mediante la orden 'other._pBuffer = nullptr;'.
*/

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test {
private:
	static const int SIZE = 100;
	int *_pBuffer{nullptr};
public:
	Test() {
		_pBuffer = new int[SIZE] {};
	}
	Test(int i) {
		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++) {
			_pBuffer[i] = 7 * i;
		}
	}
	Test(const Test &other) {
		_pBuffer = new int[SIZE] {};
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}
	Test &operator=(const Test &other) {
		_pBuffer = new int[SIZE] {};
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
		return *this;
	}

	// move constructor. No puede ser const porque va a cambiar el objeto 'other'
	Test(Test &&other){
		cout << "Move constructor" << endl;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;
	}

	~Test() {
		cout << "Destructor" << endl;
		delete [] _pBuffer;
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

	vector<Test> vec;
	vec.push_back(Test()); // ahora este método usará el move constructor

	return 0;
}