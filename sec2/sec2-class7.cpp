#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    ofstream outFile;

    string outFileName = "text.txt";

    outFile.open(outFileName);

    if (outFile.is_open()) {
        outFile << "Hola caracola" << endl;
        outFile << 123 << endl;
        outFile.close();
    } else {
        cout << "Could not open file: " << outFileName << endl;
    }

    return 0;
}
