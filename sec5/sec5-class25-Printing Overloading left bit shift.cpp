// Printing - Overloading left bit shift

/* 
	Ejercicio:
	Implementar en una clase propia el operador '<<'.	
*/

/*
	Notas:
	El operador '<<' funciona similar a un método con dos argumentos. El objeto 'cout' que pertenece a la clase ostream y en el caso de 'cout << test1 << endl' el objeto 'test1' de nuestra clase Test. Siguiendo este argumento cabría pensar que 'test1 << endl' tiene también dos parámetros, 'test1' y 'endl', sea lo que sea.

	Pero lo cierto es que algunos operadores de c++ tiene asociatividad de izquierda a derecha mientras otros la tienen de derecha a izquierda. Por ejemplo, la suma tiene asociatividad de derecha a izquierda, lo que significa que
		int value = 1 + 2 + 5  <=>  int value = 1 + (2 + 5)

	Se evalúa primero 2 + 5 y luego se valúa 1 + resultado. Sin embargo, el operador '<<' tiene asociatividad de izquierda a derecha, lo que significa que
		cout << test1 << endl  <=>  (cout << test1) << endl  (dicho esto entre comillas, porque no se pueden utilizar paréntesis en esta expresión)

	Nota: 'cout << test1' devuelve un puntero a un objeto de tipo ostream, de modo que el primer argumento de nuestro método es siempre un objeto de tipo ostream. Esto es un problema porque singifica que no podemos implementarlo como un método, ya que eso significa que implícitamente el primer argumento sería de clase Test (o la clase que lo implemente). Por tanto, tendremos que implementar una función que sobrecargue el significado de operador '<<'. Para ello, tendrá que ser una función 'friend'.

	La implementación de la función amiga iría en un fichero cpp separado, y se vería tal que así:
		ostream &operator<<(ostream &out, const Test &test){
			// hacer cosas
		}
	mientras en nuestra clase declararíamos la función amiga con 'friend ostream &operator<<(ostream &out, const Test &test)'
*/

#include <iostream>

using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test() : id(0), name("") {
	}
	Test(int id, string name) : id(id), name(name) {
	}
	Test(const Test &other) {
		id = other.id;
		name = other.name;
	}
	void print(){
		cout << id << ": " << name << endl;
	}

	const Test &operator=(const Test &other){
		*this = other;
	}

	friend ostream &operator<<(ostream &out, const Test &test){
		out << test.id << ": " << test.name;
		return out;
	}
};

int main(){

	Test test1(10, "Mike");
	Test test2(20, "Bob");



	return 0;
}