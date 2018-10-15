#include <iostream>
#include <exception>

using namespace std;

class tirarPatataException : public std::exception {
public:
	tirarPatataException() {};
	~tirarPatataException() {};

	const char* what() const throw() {
		const char* patata = "patata exception";
		return patata;
	}
};

class tirarTomateException : public std::exception {
public:
	tirarTomateException() {};
	~tirarTomateException() {};

	const char* what() const throw() {
		const char* tomate = "tomate exception";
		return tomate;
	}
};

void jeerSomething(string target) {
	if (target == "rey medieval") {
		throw tirarTomateException();
	}
	if (target == "puchero") {
		throw tirarPatataException();
	}
	throw bad_alloc();

}

int main(int argc, char const *argv[]) {

	try {
		jeerSomething("rey medieval");
	} catch (tirarTomateException &e) {
		cout << "El rey no sabe esquivar tomates: " << e.what() << endl;
	} catch (exception &e) {
		cout << "El rey esquivó tomates pero no la guillotina: " << e.what() << endl;
	}

	try {
		jeerSomething("rey esquivo");
	} catch (tirarTomateException &e) {
		cout << "El rey no sabe esquivar tomates: " << e.what() << endl;
	} catch (exception &e) {
		cout << "El rey esquivó tomates pero no la guillotina: " << e.what() << endl;
	}

	try {
		jeerSomething("puchero");
	} catch (tirarPatataException &e) {
		cout << "El puchero con papas sabe mejor: " << e.what() << endl;
	} catch (exception &e) {
		cout << "Vaya receta cochina: " << e.what() << endl;
	}
}
