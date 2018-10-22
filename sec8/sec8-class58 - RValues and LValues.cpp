/*
	Ejercicio:
	Ejemplos de RValues y LValues.

	Notas:
	En una expresión del tipo 'int value1 = 7', diremos que 'value1' es un LValue y '7' es un RValue por la posición que ocupan respecto al operador '='. En C++ 11 este concepto cambia y denominaremos LValue a cualquier cosa cuya dirección podamos extraer. Por eso, podemos escribir 'int *pValue1 = &value1', pero no 'int *pValue2 = 7'.

	Esto se aplica también a objetos y funciones. Cuando escribimos 'Test test1 = getTest();', 'test1' es un LValue mientras que 'getTest()' es un RValue. La función en este caso devuelve un objeto como RValue.

	A veces esta distinción es un poco confusa, porque por ejemplo podríamos escribir 'int *pValue3 = &++value1;' sin que diera problema. Sin embargo, 'int *pValue4 = &value1++;' sí que da problemas porque el operador post incremento funciona de la siguiente manera:
	- Utiliza el valor antiguo para crear una copia
	- Incrementa el valor
	- Devuelve una copia del valor antiguo
	Sin embargo, el operador preincremento no necesita crear una copia, ya que trabaja directamente sobre el objeto y lo devuele incrementado. Esto explica por qué podemos tomar la dirección con el operador preincremento (sigue siendo el mismo objeto) pero no post incremento (es una copia temporal del objeto antes de incrementarlo).

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

	int value1 = 7;

	int *pValue1 = &value1;
	// int *pValue2 = 7

	Test *pTest1 = &test1;
	// Test *pTest2 = &getTest();

	int *pValue3 = &++value1;
	cout << *pValue3 << endl;

	// int *pValue4 = &value1++;

	// int *s = &(7 + value1);
	// Esto es un RValue aún cuando value1 es un LValue

	return 0;
}