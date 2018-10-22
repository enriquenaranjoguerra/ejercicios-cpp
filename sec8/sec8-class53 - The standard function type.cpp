/*
	Ejercicio:
	Crear algo similar que multiplique dos números.

	Notas:
	'function' es una palabra reservada de C++ 11 que nos permite definir una función como parámetro de otra función o método. Es una plantilla, por lo que habrá que pasar entre '<>' el tipo de función que es, primero el tipo de retorno, después entre paréntesis los parámetros que acepta y luego el nombre. Así, si queremos definir una función que devuelve un 'bool', acepta como parámetro un 'string' y se llamará 'check', escribiremos 'function<bool(string)> check'.

	Buscar 'types callable'

*/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string &test) {
	return test.size() == 3;
}

class Check {
public:
	bool operator()(string &test) {
		return test.size() == 3;
	}
} check1;

void run(function<bool(string&)> check) {
	string test = "dog";
	cout << check(test) << endl;
}

int main() {

	int size = 5;
	vector<string> vec{"one", "two", "three"};
	auto lambda = [size](string test) {return test.size() == size;};

	int count = count_if(vec.begin(), vec.end(), lambda);
	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), check);
	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), check1);
	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), check1);
	cout << count << endl;

	run(lambda);
	run(check1);
	run(check);

	function<int(int, int)> add = [](int a, int b) {return a + b;};
	cout << add(7, 3) << endl;

	return 0;
}