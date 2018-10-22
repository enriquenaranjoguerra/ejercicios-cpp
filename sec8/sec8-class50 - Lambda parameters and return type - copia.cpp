/*
	Ejercicio:
	Definir una función lambda que acepte parámetros y devuelva distintos tipos.

	Notas:
	En una expresión lambda, los parámetros van entre los paréntesis después de los corchetes. El tipo de retorno no es necesario siempre que C++ pueda inferir con exactitud qué tipo de retorno tiene una expresión lambda. Normalmente eso será cuando haya un solo 'return'.

	Por otro lado, una expresión lambda puede tener varios 'return', por ejemplo, por tener un 'if. Si devuelven distintos clases de objeto o distintos tipos, C++ no puede inferir el tipo y hay que especificárselo. Esto se hace entre los paréntesis y las llaves mediante una flecha: '[]() -> tipo_retorno { código };'

*/

#include <iostream>

using namespace std;

void testGreet(void (*greet)(string)) {
	greet("Bob");
}

void runDivide(double (*divide)(double, double)) {
	auto rval = divide(9, 3);
	cout << rval << endl;
}

int main() {

	auto pGreet = [](string name) { cout << "Hello " << name << endl; };
	pGreet("Mike");

	testGreet(pGreet);
	testGreet([](string name) { cout << "Hello " << name << endl; });

	cout << endl;

	auto pDivide = [](double a, double b) -> double {
		if (b == 0.0) {
			return 0;
		}
		return a / b;
	};

	cout << pDivide(10.0, 5.0) << endl;
	cout << pDivide(10.0, 0) << endl;

	runDivide(pDivide);

	return 0;
}