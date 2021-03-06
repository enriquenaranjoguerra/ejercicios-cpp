/* Ejercicio
	crear una estructura, guardarla y leerla metiéndola en otra estructura similar
*/

#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Person {
	char name[50];
	int age;
	double height;
};
#pragma pack(pop)

int main(){

	Person someone = {"Frodo", 220, 0.8};
	string fileName = "test.bin";
	ofstream outputFile;
	outputFile.open(fileName, ios::binary);

	if (outputFile.is_open()) {
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
		outputFile.close();
	} else {
		cout << "Could not create file " + fileName << endl;
	}

	// Read binary file
	Person someoneElse = {};
	ifstream inputFile;
	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open()) {
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
		inputFile.close();
	} else {
		cout << "Could not read file " + fileName << endl;
	}

	cout << "someoneElse name: " << someoneElse.name << ", someoneElse age: " << someoneElse.age << ", someoneElse height: " << someoneElse.height << endl;

	return 0;
}
