// Inicialization in C++ 11

/*
	Ejercicio:


	Notas:
	C++ 11 generaliza el uso de llaves {} y nos permite inicializar valores directamente sin usar el operador de asignación =.

	Así podemos crear un int y asignarle el valor 5 o un string y asignarle el valor "Hello". Podemos hacerlo también con un array de forma similar a C++ 98 (ejemplo 1).

	Podemos hacerlo cuando usamos new para un array, pero necesitaremos especificar el número de elementos (ejemplo 2).

	Si dejamos las llaves vacías, se inicializará al valor por defecto, que en int es 0 y en string es una cadena vacía (ejemplo 3).

	Esto también funciona con punteros. En este caso, el valor por defecto es un puntero que no apunta a nada. Para esto, C++ 11 introduce una nueva palabra clave, 'nullptr', específica para inicializar punteros (ejemplo 4)

	Para arrays inicializados con las llaves vacías, todos los elementos se inicializan al valor por defecto (ejemplo 5).

	Para estructuras o clases, vimos que podíamos declarar e inicializar variables a continuación de la clase o estructura usando el operador de asignación. Ahora ese operador no es necesario, como consistencia con los demás usos (ejemplo 6). Veremos que podemos dar valores por defecto a los miembros de una clase, pero hay que tener cuidado, porque así se pierden los constructores por defecto, lo que implica no poder usar las llaves. Para volver a usarlas, necesitaríamos un constructor apropiado.

	Por último, pero no menos importante, podemos instanciar una clase vector llena de elementos con llaves. Hasta ahora no era posible porque con un array se colocan los elementos uno a continuación de otro en la memoria, lo cual es una operación simple. Pero vector es un tipo de dato más complejo.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

	cout << "Ejemplo 1" << endl;
	int value{5};
	cout << value << endl;
	string text{"Hello"};
	cout << text << endl;
	int numbers[] {1, 2, 3};
	cout << numbers[1] << endl;
	cout << endl;

	cout << "Ejemplo 2" << endl;
	int *pInts = new int[3] {1, 2, 3};
	cout << pInts[1] << endl;
	delete pInts;

	cout << "Ejemplo 3" << endl;
	int value1{};
	cout << value1 << endl;
	string text1{};
	cout << text1 << endl;

	cout << "Ejemplo 4" << endl;
	int *pSomething{&value};
	cout << *pSomething << endl;
	int *pSomething1{};
	cout << *pSomething1 << endl;
	int *pSomething2 = nullptr; //esto mejor que int *pSomething2 = NULL;
	cout << *pSomething2 << endl;

	cout << "Ejemplo 5" << endl;
	int numbers1[5] {};
	cout << numbers1[1] << endl;
	cout << endl;

	cout << "Ejemplo 6" << endl;
	struct {
		// 'int value = 7;' haría que toda instancia tuviera value = 7, pero nos impediría usar llaves para instanciar s1 a menos que definamos un constructor apropiado
		int value;
		string text;
	} s1{5, "Hi"};
	cout << s1.text << endl;
	cout << endl;

	cout << "Ejemplo 7" << endl;
	vector<string> strings {"one", "two", "three"};
	cout << strings[2] << endl;
	cout << endl;

	return 0;
}