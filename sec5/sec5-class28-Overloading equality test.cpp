// Overloading equality test

/* 
	Ejercicio:
		
*/

/*
	Notas:
	El operador '==' tiene dos parámetros, el primero es el parámetro implícito 'this', por lo que la implementación del método solo necesitará un parámetro. Este parámetro será el otro número complejo con el que queremos comparar. La implementación del operador '!=' es bastante similar.
*/

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace caveofprogramming;

int main(){

	Complex c1(3, 2);
	Complex c2(3, 2);
	Complex c3(3, 4);

	cout << (c1 == c2) ? ("Equals") : ("Not equals") << endl;
	cout << (c1 == c3) ? ("Equals") : ("Not equals") << endl;

	cout << (c1 != c2) ? ("Not Equals") : ("Equals") << endl;
	cout << (c1 != c3) ? ("Not Equals") : ("Equals") << endl;

	return 0;
}