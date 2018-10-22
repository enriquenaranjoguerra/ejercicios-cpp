/*
	Ejercicio:



	Notas:
	Cuando tenemos un puntero a una clase padre y lo casteamos a una clase hijo, podemos tener problemas con métodos exclusivos de la clase hijo. Estaría bien alguna forma de comprobar en tiempo de ejecución si tiene sentido y que devuelva un nullptr si no tiene sentido. Ojo con los no hacer los métodos heredables, si no tienen la palabra 'virtual' habrá problemas.
*/

#include <iostream>


using namespace std;

class Parent {
public:
	virtual void speak(){
		cout << "Parent!" << endl;
	}
};

class Brother : public Parent {
};

class Sister : public Parent {
};

int main() {

	Parent parent;
	Brother brother;
	Parent *ppb = &parent;
	Brother *pbb = dynamic_cast<Brother *> (ppb);
	if (pbb == nullptr) {
		cout << "Invalid cast" << endl;
	} else {
		cout << pbb << endl;
	}

	Parent *ppb1 = &brother;
	Brother *pbb1 = dynamic_cast<Brother *> (ppb1);
	if (pbb1 == nullptr) {
		cout << "Invalid cast" << endl;
	} else {
		cout << pbb1 << endl;
	}

	return 0;
}