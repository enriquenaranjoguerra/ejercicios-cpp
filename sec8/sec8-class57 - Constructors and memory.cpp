/*
	Ejercicio:


	Notas:
	Si queremos inicializar un vector con un valor determinado, podemos hacerlo con la palabra 'memset'. También podemos usar llaves vacías para fijar los valores a 0 si usamos C++ 11.

	Buscar las palabras clave 'memset' y 'memcpy'.


*/

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test {
private:
	static const int SIZE = 100;
	int *_pBuffer;
public:
	Test() {
		cout << "Constructor" << endl;
		// _pBuffer = new int[SIZE];
		// memset(_pBuffer, 0, sizeof(int)*SIZE);
		_pBuffer = new int[SIZE] {};
	}
	Test(int i) {
		cout << "Parametrized constructor" << endl;
		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++) {
			_pBuffer[i] = 7 * i;
		}
	}
	Test(const Test &other) {
		cout << "Copy constructor" << endl;
		_pBuffer = new int[SIZE] {};
		memcpy(_pBuffer, other, _pBuffer, SIZE * sizeof(int));
	}
	Test &operator=(const Test &other) {
		cout << "Assignment" << endl;
		_pBuffer = new int[SIZE] {};
		memcpy(_pBuffer, other, _pBuffer, SIZE * sizeof(int));
		return *this;
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

	Test test1 = getTest();
	cout << test1 << endl;

	vector<Test> vec;
	vec.push_back(Test());



	return 0;
}