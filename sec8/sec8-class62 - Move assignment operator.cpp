/*
	Ejercicio:
	Probar el 'move assignment operator' en nuestra propia clase.


	Notas:
	Cuando utilizamos el 'move assignment operator', lo primero que tenemos que hacer es desasignar la memoria asignada a los elementos de nuestra clase. Como aquí tenemos un puntero a int, tenemos que usar la versión array de delete: 'delete [] _pBuffer;'.
*/

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test {
private:
	static const int SIZE = 100;
	int *_pBuffer{ nullptr };
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

	// move assignment operator
	Test &operator=(Test &&other) {

		cout << "Move assignment constructor" << endl;

		delete [] _pBuffer;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;

		return *this;
	}

	// move constructor. No puede ser const porque va a cambiar el objeto 'other'
	Test(Test &&other) {
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

	Test test;
	test = getTest(); // move assignment constructor

	return 0;
}