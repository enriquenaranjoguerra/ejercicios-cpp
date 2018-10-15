/* Ejercicio
	comprobar el sizeof de dos estructuras, una con el pragma y otra sin él
*/

#include <iostream>

using namespace std;

#pragma pack(push, 1)

struct Person {
	char name[50];
	int age;
	double weight;
};

#pragma pack()

struct Job {
	char name[50];
	int salary;
	double age;
};

int main() {

	cout << "Tamaño de char[50]: " << sizeof(char[50]) << endl;
	cout << "Tamaño de int: " << sizeof(int) << endl;
	cout << "Tamaño de double: " << sizeof(double) << endl;
	cout << "Tamaño de Person (con pragma): " << sizeof(Person) << endl;
	cout << "Tamaño de Job (sin pragma): " << sizeof(Job) << endl;

	return 0;

}