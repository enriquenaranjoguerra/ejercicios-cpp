// Template classes

/*
	Ejercicio:
	Usar esta clase plantilla y pasarle otro objeto que también tenga implementado el operador '<<' para llamar al método 'print()'. Esta plantilla debería tener dos parámetros, T y K.
*/

#include <iostream>

using namespace std;

//template<class T>
template<class T, class K>
class Test {
private:
	T t;
	K k;

public:
	Test(T t, K k) : t(t), k(k) {
	}

	void print() {
		cout << "Parámetro t: " << t << ", parámetro k: " << k << endl;
	}
};

int main() {

	Test<string, int> test1("Hello", 5);
	test1.print();

	return 0;
}