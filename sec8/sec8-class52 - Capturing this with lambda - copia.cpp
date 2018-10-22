/*
	Ejercicio:
	Probar estas cosas, como siempre

	Notas:
	Si tenemos una clase con un método run() y ese método tiene unas variables 'three' y 'four', vimos que podíamos capturarlas con los corchetes []. Sin embargo, no podemos usar estos corchetes para capturar las variables 'one' y 'two', ya que son variables de instancia y daría un error de compilación.

	Sin embargo, sí podemos capturar toda la instancia del objeto pasando 'this' dentro de los corchetes. A partir de entonces sí podremos usar las variables de la instancia como si las hubiéramos capturado. Estas variables se capturan por referencia. Si pusiéramos un igual al principio de los corchetes para capturarlo todo por valor, el 'this' nos daría problemas y no nos dejaría.

*/

#include <iostream>

using namespace std;

class Test {
private:
	int one{1};
	int two{2};
public:
	run(){
		int three{3};
		int four{4};

		auto pLambda = [this, three, four](){
			one = 111;
			cout << one << endl;
			cout << two << endl;

			cout << three << endl;
			cout << four << endl;
		};
		pLambda();
	}
};

int main() {

	Test test;
	test.run();

	return 0;
}