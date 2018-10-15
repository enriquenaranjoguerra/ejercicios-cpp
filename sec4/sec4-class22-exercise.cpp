// Sorting vectors, Deque and Friend

/*
	Ejercicio:
	Crear alguna clase con una serie de campos y tratar de ordenarlos de ambas formas posibles
	implementando el operador '<' y utizando la palabra reservada 'friend'.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void printScores(vector<double> &scores) {
	cout << "Printing scores" << endl;
	for (double score : scores) {
		cout << score << endl;
	}
}

double calculateAverageScore(vector<double> &scores) {
	double sum = 0.0;
	double amount = 0.0;
	for (double score : scores) {
		sum += score;
		amount++;
	}
	return (sum / amount);
}

class Student {
private:
	string m_name;
	vector<double> m_scores;
	double m_averageScore;
public:
	Student(string name, vector<double> &scores) :
		m_name(name), m_scores(scores) {
		m_averageScore = calculateAverageScore(scores);
	}
	void print() {
		cout << "Student name: " << m_name << ", student scores: " << endl;
		printScores(m_scores);
		cout << "Average score: " << m_averageScore << endl;
		cout << endl;
	}

	bool operator<(const Student &other) const {
		if (m_averageScore == other.m_averageScore) {
			return m_name < other.m_name;
		}
		return m_averageScore < other.m_averageScore;
	}

//	friend bool comp(const Student &a, const Student &b);
};

//bool comp(const Student &a, const Student &b){
//	if(a.name == b.name){
//		return a.totalScore < b.totalScore;
//	}
//	return a.name < b.name;
//}

int main() {

	vector<double> mikeScores;
	mikeScores.push_back(10.0);
	mikeScores.push_back(15.0);
	mikeScores.push_back(20.0);

	vector<double> sueScores;
	sueScores.push_back(18.0);
	sueScores.push_back(16.0);

	vector<double> pepeScores;
	pepeScores.push_back(16.0);
	pepeScores.push_back(14.0);
	pepeScores.push_back(13.0);
	pepeScores.push_back(19.0);

	set<Student> students;
	Student m_mike = Student("Mike", mikeScores);
	Student m_sue = Student("Sue", sueScores);
	Student m_pepe = Student("Pepe", pepeScores);

//	cout << "¿Es Mike peor que Sue?" << endl;
//	cout << ((m_mike < m_sue) ? "Sí" : "No" ) << endl;

	students.insert(m_mike);
	students.insert(m_sue);
	students.insert(m_pepe);

//	sort(students.begin(), students.end(), comp);

	for (Student student : students) {
		student.print();
	}

	return 0;
}