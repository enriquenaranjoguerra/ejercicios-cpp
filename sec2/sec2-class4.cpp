#include <iostream>
using namespace std;

int memoryNeeded = 10;
int i = 2;


class LotsOfMemoryNeeded {
public:
	LotsOfMemoryNeeded() {
		char *pMemory = new char[memoryNeeded];
		delete[] pMemory;
	}

};

int main(int argc, char const *argv[]) {

	try {
		for (; i < 100; ++i) {
			LotsOfMemoryNeeded meec;
			memoryNeeded = memoryNeeded * i;
		}
	} catch (bad_alloc &e) {
		cout << "Too much memory needed. Index: " << i << ", memory needed: " << memoryNeeded << endl;
		cout << "Exception: " << e.what() << endl;
	}

	cout << "Still running" << endl;

}
