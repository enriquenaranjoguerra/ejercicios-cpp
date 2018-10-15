// Object slicing and polymorfism

/*
	Ejercicio:


	Notas:
	Supongamos que tenemos dos clases, Parent y Child, una instancia de hijo y una referencia a un objeto Parent que apunta a la instancia del objeto hijo. Ambas clases tienen el método 'print', salvo que cada una imprime el tipo al que pertenece. Entonces, si &p1 es la referencia al objeto tipo Parent, ¿imprimirá Parent o Child?

	La respuesta es Parent, contra todo pronóstico. Esto sucede porque, de momento, no hemos puesto la palabra clave 'virtual' delante de la cabecera del método 'print' en la clase Parent. Con la palabra 'virtual', podremos heredar el método e imprimir el valor correcto.

	Esto es lo que se conoce como polimorfismo y permite que el objeto c1, que es de la clase Child, se pueda considerar en caso de necesitarlo, de la clase Parent. Esto se aplica también a referencias. Uno puede tener una referencia a un objeto de un tipo Parent apuntando a un objeto de tipo Child, como nuestro caso.

	El polimorfismo nos permite también instanciar un objeto de la clase Parent llamando a un constructor de la clase Child.

	Si definimos un constructor en la clase Parent, y por tanto, perdemos el constructor por defecto, debemos o bien recuperar el constructor por defecto o indicar qué constructor queremos utilizar de la clase padre. Por tanto, si definimos el constructor copia, perdemos el constructor por defecto.

	Un constructor de la clase Parent puede inicializar los valores de la clase Parent, como 'one', pero no los de la clase Child, como 'two', ya que no sabe que existen.

*/

#include <iostream>

using namespace std;

class Parent {
private:
	int one;
public:
	Parent(): one(0) {
	}

	Parent(const Parent &other): one(0) {
		one = other.one;
		cout << "copy parent" << endl;
	}
	// sin 'virtual' llama a este método, no al hijo
	virtual void print() {
		cout << "parent" << endl;
	}
};

class Child: public Parent {
private:
	int two;
public:
	Child(): two(0) {
	}
	void print() {
		cout << "child" << endl;
	}
};

int main() {
	Child c1;
	Parent &p1 = c1;
	p1.print();

	// constructor copia
	Parent p2 = Child();
	p2.print();

	return 0;
}