/*
	Ejercicio:
	Buscar algo más de LValue.

	Notas:
 	Normalmente no podríamos escribir algo como 'Test &rTest2 = getTest();', ya que el valor de retorno de una función es un RValue y no podemos extraer su dirección. Sin embargo, usando la palabra 'const' extendemos la vida del objeto temporal que devuelve la función 'getTest()' y lo vinculamos a la variable rTest2. La variable temporal dejará de existir cuando 'rTest2' deje de existir a su vez.


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
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}
	Test &operator=(const Test &other) {
		cout << "Assignment" << endl;
		_pBuffer = new int[SIZE] {};
		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
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

	Test &rTest1 = test1;
	// Test &rTest2 = getTest(); No funciona
	const Test &rTest2 = getTest();

	Test test2(Test(1));

	return 0;
}