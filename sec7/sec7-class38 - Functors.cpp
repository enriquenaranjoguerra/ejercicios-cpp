// Functors

/*
	Ejercicio:
	Crear nuestro propio functor que haga algo.

	Notas:
	El operador paréntesis () es el único que admite como argumento una cantidad variable de argumentos. Los demás operadores admiten una cantidad concreta, pero los paréntesis admiten 0, 1 o cuantos sean.

	Definimos un functor como una clase o estructura que sobrecarga el operador (). Se les llama así porque al instanciar un objeto de la clase MatchTest, que es la que sobrecarga el operador (), parece que estamos llamando a una función al usar el operador (). Si la instancia se llama 'pred' y queremos usar () con la cadena 'value = "lion"', lo haremos mediante 'pred(lion)', que parece una función, aunque no lo sea.

	Mediante polimorfismo, cada clase o estructura que herede de Test puede implementar el operador () a su manera, de modo que cada clase o estructura tiene su propio test.

*/

#include <iostream>

using namespace std;

struct Test {
	virtual bool operator()(string &text) = 0;
};

struct MatchTest : public Test {
	bool operator()(string &text) {
		return text == "lion";
	}
};

void check(string text, Test &test) {
	if(test(text)){
		cout << "Text matches!" << endl;
	} else {
		cout << "No match" << endl;
	}
}

int main() {

	MatchTest pred;
	string value = "lion";
	//cout << pred(value) << endl;
	MatchTest m;
	check("lion", m);
	check("liond", m);

	return 0;
}