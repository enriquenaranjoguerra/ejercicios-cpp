// Using function pointers

/*
	Ejercicio:
	Crear una función propia y pasársela a un vector de elementos. Por ejemplo, una función que cuente el número de veces que un programa pasa por un trozo de código.


	Notas:
	Supongamos que tenemos un vector con valores de tipo cadena y una función que devuelve true si le pasamos una cadena de 3 caracteres y false en otro caso. ¿Cómo podríamos aplicar esta función a todo el vector?

	C++ incluye una función para esto llamada 'count_if'. Como argumentos se le pasa un iterador que empiece en el primer elemento que queramos comprobar, otro iterador apuntando al final y un puntero a una función que devuelve un bool y que acepta como parámetro un elemento del tipo del vector.

	¿Y si quisiéramos implementar nuestra versión de la función 'count_if' u otra cualquiera? Supongamos que vamos a implementar la función countStrings a la que le pasaremos un vector y una función que evaluará cada elemento del vector. El primer parámetro de esta función sería una referencia a un vector, por lo que lo escribiríamos, como de costumbre, 'vector<string> &nombreDelParametro'.

	Lo nuevo entra en el segundo parámetro. Escribiríamos el tipo de retorno de la función, que en este caso es 'bool', el nombre de la variable entre paréntesis y precedido de asterisco y luego entre otros paréntesis los parámetros de la función. Quedaría de la forma 'bool *(nombreVariableFuncion)(tipo1 param1, tipo2 param2)'.


*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test) {
	// return test == "two";
	return test.size() == 3;
}

int countStrings(vector<string> &texts, bool * (match)(string test) ) {
	int tally = 0;
	for (int i = 0; i < texts.size(); i++) {
		if (match(texts[i])) {
			tally++;
		}
	}
	return tally;
}

int main() {

	vector<string> texts;

	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("two");
	texts.push_back("four");
	texts.push_back("two");
	texts.push_back("three");

	cout << match("one") << endl;
	cout << count_if(texts.begin(), texts.end(), match) << endl;
	cout << countStrings(texts, match) << endl;


	return 0;
}