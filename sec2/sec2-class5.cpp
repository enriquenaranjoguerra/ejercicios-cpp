// no se están capturando las excepciones

#include <iostream>
#include <exception>
using namespace std;

string ingredient;

class NoIngredientException : public exception {
public:
	NoIngredientException() {
	}
	const char* what() const throw() {
		return ("No tenemos este ingrediente: " + ingredient).c_str();
	}
};

class TortillaDePapas {
public:
	TortillaDePapas(int numHuevos, int kilosDePapas) {
		if (numHuevos == 0) {
			ingredient = "huevos";
			throw new NoIngredientException();
		}
		if (kilosDePapas == 0) {
			ingredient = "papas";
			throw new NoIngredientException();
		}
		huevos = numHuevos;
		papas = kilosDePapas;
	}

private:
	int huevos;
	int papas;

};

int main(int argc, char const *argv[]) {

	try {
		new TortillaDePapas(0, 0);
	} catch (NoIngredientException &e) {
		cout << e.what() << endl;
	}

	try {
		new TortillaDePapas(1, 0);
	} catch (NoIngredientException &e) {
		cout << e.what() << endl;
	}

	try {
		new TortillaDePapas(10, 1);
	} catch (NoIngredientException &e) {
		cout << e.what() << endl;
	}

	cout << "Still running" << endl;

}
