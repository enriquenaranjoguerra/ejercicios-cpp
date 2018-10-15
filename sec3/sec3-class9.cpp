#include <iostream>
#include <fstream>

using namespace std;

int main(){

	string filename = "data.txt";
	ifstream input;

	input.open(filename);
	
	if(!input.is_open()){
		return 1;
	}
	
	while(input){
		string line;
		
		getLine(input, line, ':');
		
		int population;
		intput >> population;
		
		//input.get();
		input >> ws;
		
		if(!input) {
			break;
		}
		
		cout << "'" << line << "' -- '" << population << "'" << endl;
	}
	
	input.close();

	return 0;

}