#include <iostream>
using namespace std;

void checkDenominator(double);
double division(double, double);

int main(int argc, char const *argv[])
{
	try{
		division(4.0, 2.0);
		division(4.0, 0.0);
	} catch (string &e) {
		cout << "Ocurrió un problema: " << e << endl;
	}

	return 0;
}

double division(double num, double denom){
	checkDenominator(denom);
	cout << "El resultado de dividir " << num << " entre " << denom << " es: " << num / denom << endl;
	return num / denom;
}

void checkDenominator(double num){
	if(num == 0){
		throw string("el 0 no es un denominador válido en los números reales.");
	}
}
