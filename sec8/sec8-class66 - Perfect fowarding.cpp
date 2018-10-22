/*
	Ejercicio:


	Notas:
	La idea del perfect forwarding es que querrás usar la versión correcta de una función sobrecargada dependiendo de si una función como la 'call' recibe un lvalue o un rvalue.

	Buscar reference collapsing

*/

#include <iostream>

using namespace std;

class Test {
};

template<class T>
void call(T &&arg){
	// check(arg);
	// check(static_cast<T>(arg));
	check(forward<T>(arg));
}

void check(Test &test){
	cout << "lvalue" << endl;
}

void check(Test &&test){
	cout << "rvalue" << endl;
}

int main() {

	Test test;
	call(Test()); // esto no sería perfect forwarding sin el static_cast o el forward porque meto un rvalue en la función call pero sin embargo se llama a la función check para lvalue.
	call(test);

	return 0;
}