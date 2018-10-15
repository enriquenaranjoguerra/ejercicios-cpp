// Template functions

/*
	Ejercicio:
	Crear un programa donde poner el tipo o no conlleve a un comportamiento diferente. Pista: podemos sobrecargar funciones que se comporten distinto según el argumento que estemos pasándole.
*/

/*
	Notas:
	De forma similar a las clases plantilla, las funciones plantilla necesitan uno o varios parámetros que podremos usar como argumentos en la función. Si quiero hacer una función plantilla llamada 'print', tendré que escribir 'template<class T>' antes de la declaración de la función.

	Para poder llamarla correctamente, tendré que suministrar el tipo de parámetro mediante '<>' y que este concuerde con lo que estoy pasando. En el ejemplo de antes, se llamaría mediante 'print<string>("Hola mundo")'. Si escribiese 'print<string>(5)', daría un error de compilación. También se puede llamar directamente con 'print("Hola mundo")', ya que el compilador infiere el tipo.

	En vez de la palabra 'class', podríamos usar la palabra 'typename', ya que T no necesariamente va a ser una clase. Puede ser, por ejemplo, un tipo primitivo, como 'int'. Aún así, es indiferente usar cualquiera de las dos palabras, ya que 'class' funciona con tipos primitivos como 'int'.
*/

#include <iostream>

using namespace std;

template<class T>
void print(T n){
	cout << n << endl;
}

int main() {

	print<string>("Hello");
	print<int>(5);



	return 0;
}