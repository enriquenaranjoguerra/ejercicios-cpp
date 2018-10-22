/*
	Ejercicio:
	Escribir todo esto.

	Notas:
 	Los RValues los utilizaremos para no tener que andar usando los constructores copia y aumentar la eficiencia.


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

void check(const Test &value){
	cout << "LValue function" << endl;
}

void check(Test &&value){
	cout << "RValue function" << endl;
}

int main() {

	Test test1 = getTest();
	cout << test1 << endl;

	vector<Test> vec;
	vec.push_back(Test());

	Test &test1 = test1;
	// Test &&rTest1 = Test();
	Test &&rTest1 = getTest();

	check(test1); // pasamos a la función un LValue
	check(getTest()); // pasamos a la función un RValue
	check(Test()); // pasamos a la función un RValue



	return 0;
}