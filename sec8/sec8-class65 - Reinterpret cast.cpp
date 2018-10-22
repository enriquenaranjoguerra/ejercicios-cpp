/*
	Ejercicio:


	Notas:
	reinterpret_cast cambia un puntero de un objeto a otro. En cierto sentido, vale para castear de cualquier cosa a cualquier cosa. Esto sucede porque reinterpret_cast comprueba incluso menos que static_cast.

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
	Sister sister;

	Parent *ppb = &brother;
	Sister *pbb = reinterpret_cast<Sister *> (ppb); // castear brother a sister
	if (pbb == nullptr) {
		cout << "Invalid cast" << endl;
	} else {
		cout << pbb << endl;
	}



	return 0;
}