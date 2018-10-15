// Template functions and type inference

/*
	Ejercicio:
	En algunas situaciones, es necesario poner no solo el operador diamante para que compile, sino también el tipo de parámetro. Buscar una situación donde esto suceda.
*/

/*
	Notas:
	Estamos usando la función 'print' sobrecargada como ejemplo. Si llamamos a print solo con un 5 como argumento, c++ considerará que el mejor candidato es 'print(int n)', ya que su argumento es específicamente un int. Si queremos forzar el uso de la función con parámetro, tenemos que usar el operador diamante. No es necesario especificar el tipo dentro del diamante, ya que el compilador lo infiere.

	Si creamos una función plantilla donde alguno de los parámetros no es un argumento pero se usa en el cuerpo, es necesario el operador diamante porque si no, el compilador no inferir qué tipo es T. No solo necesita el operador diamante, sino que necesita además el tipo, ya que sin él, sigue sin poder inferir.
*/

#include <iostream>

using namespace std;

template<class T>
void print(T n){
	cout << "Template version: " << n << endl;
}

void print(int value){
	cout << "Non template version: " << value << endl;
}

template<template T>
void show(){
	cout << T() << endl;
}

int main() {

	// template functions
	print<string>("Hello");
	print<int>(5);
	print("Hi there"); //type infered without diamond
	print<>(5); //type infered with diamond

	// non template function
	print(5);

	// show() no compila
	show<double>();

	return 0;
}