// STD Complex Data Type

/* 
	Ejercicio:
	Inventar una estructura de datos que consista en un conjunto (set) de vectores
	
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

	map<string, vector<int> > scores;

	scores["Mike"].push_back(10);
	scores["Mike"].push_back(20);
	scores["Vicky"].push_back(15);

	for(map<string, vector<int> >::iterator it = scores.begin(); it != scores.end(); it++){
		cout << "Puntuaciones de " << it->first << endl;
		int i = 1;
		vector<int> scoreList = it->second;
		for(vector<int>::iterator itv = scoreList.begin(); itv != scoreList.end(); itv++){
			cout << "Puntuación " << i++ << ": " << *itv << endl;
		}

		cout << endl;
	}

	return 0;
}