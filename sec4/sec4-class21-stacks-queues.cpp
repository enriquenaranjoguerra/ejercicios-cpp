// Stacks and Queues

/*
	Ejercicio:
	- Opcional: hace un menú similar al de vectores para meter y sacar información por la
	consola.
*/

/*
	Notas:
	stack (pila) es una estructura de tipo 'ultima que entra, primera que sale', cuyo acrónimo
	en inglés es LIFO. Para introducir un elemento en la pila tenemos que usar el método 'push'
	y para sacarlo utilizamos el método 'pop'. Estos dos métodos son 'void', ya que no devuelven
	ningún elemento. Podemos ver el último elemento introducido mediante el método 'top', sin
	alterar la pila.

	No se puede iterar sobre las pilas, si quisiéramos iterar, deberíamos buscar otra estructura
	más acorde a lo que queremos.

	En estas clases del STD de 'colecciones' (usando terminología de Java), métodos como stack.top()
	nos devuelven un puntero al objeto en cuestión. Esto significa que si utilizamos el operador
	'=', estamos copiando el objeto a una nueva variable con el constructor copia por defecto si
	hace falta. También significa que cuando añadimos objetos a la pila, se destruye el objeto
	original.

	Para ser realmente eficientes, tendríamos que colocar un '&' delante de la variable donde iríamos
	a copiar el elemento. Por ejemplo, en vez de 'Test test1 = testStack.top();', tendríamos que
	escribir 'Test &test1 = testStack.top();'. Sin embargo, hay que tener cuidado con un detalle:
	si hacemos pop después de esto, ya no podremos confiar en la variable test1, dado que la referencia
	se ha descartado. Es posible que funcione, pero esa zona de memoria no sabemos qué contiene.

	queue (cola) es una estructura similar pero de tipo 'primero que entra, primero que sale', cuyo
	acrónimo en inglés es FIFO. Conceptualmente, una cola es similar a una cola en un supermercado y
	tiene un sentido más "horizontal". Por eso no existe el método 'top', sino el método 'front', que
	nos devolverá el objeto más antiguo. Además, existe el método 'back', que nos devolverá el último
	elemento que entró en la cola.
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
	string name;
public:
	Test(string name) :
		name(name) {
		cout << "Creating object " << name << endl;
	}

	~Test() {
		// cout << "Destroying the object " << name << endl;
	}
	void print() {
		cout << name << endl;
	}
};

int main() {

	stack<Test> testStack;

	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Sue"));

	cout << endl;

	// Este código no es correcto porque la referencia a test1 se ha perdido
	/*
	Test &test1 = testStack.top();
	testStack.pop();
	test1.print();
	*/

	while (testStack.size() > 0) {
		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}

	cout << endl;

	queue<Test> testQueue;

	testQueue.push(Test("Mike"));
	testQueue.push(Test("John"));
	testQueue.push(Test("Sue"));

	cout << "La última persona que entró a la cola es " <<
	     testQueue.back().print() << endl;

	while (testQueue.size() > 0) {
		Test &test = testQueue.front();
		test.print();
		testQueue.pop();
	}

	return 0;
}