/*
	Ejercicio:
	Castear subclases a super clases usando punteros.


	Notas:
	Tenemos varias formas de castear un objeto a otro tipo: con paréntesis delante (estilo C), con un constructor apropiado (C++), mediante static_cast (C++ 11) o mediante polimorfismo.

	Respecto a esto, podemos tener punteros de la clase padre apuntando a la dirección de un objeto hijo haciendo 'Parent *ppb = &brother;'. Como es evidente, también podemos crear un puntero de tipo hijo que apunte a la dirección de un objeto hijo: 'Brother *pbb = &brother;'. Pero lo interesante aquí es que el segundo puntero le podríamos asignar el primer puntero, utilizando el static_cast.

	El problema de esto es que static_cast se hace en tiempo de ejecución. Los problemas los dará sobre la marcha si llamamos a un método exclusivo de la clase Brother, que no estarán disponibles en la clase Parent.

	Podemos escribir 'Parent &&p = Parent();' para asignar a una variable 'p' un RValue que sale del constructor 'Parent'. Pero ¿y si queremos asignar un LValue, por ejemplo con 'Parent &&p = parent;'? Tal cual no funcionaría, pero podemos hacer un static_cast para que funcione.

*/

#include <iostream>


using namespace std;

class Parent {
public:
	void speak(){
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

	float value = 3.23;
	cout << "C casting '(int)value': " << (int)value << endl;
	cout << "C++ casting by constructor 'int(value)': " << int(value) << endl;
	cout << "C++ static_cast casting 'static_cast<int>value': " << static_cast<int>value << endl;
	cout << endl;

	// Parent *pp = &brother; casting by polimorfism
	// Brother *pb = static_cast<Brother *>(&parent); muy inseguro, no recomendado porque Brother puede tener métodos de los que no dispone Parent y al llamarlos el programa fallaría.
	Parent *ppb = &brother;
	Brother *pbb = static_cast<Brother *> (ppb);
	cout << pbb << endl;

	// Parent &&p = Parent();
	Parent &&p = static_cast<Parent &&>(parent);
	p.speak();

	return 0;
}