// Object Initialization, Default and Delete

/*
	Ejercicio:


	Notas:


*/

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Test {
	int id{3}; // int id = 3;
	string name{"Mike"};

public:
	public Test(int id) : id(id) {
	}
	void print() {
		cout << id << ": " << name << endl;
	}
};


int main() {

	Test test;
	test.print();

	Test test1(77);
	test1.print();

	return 0;
}