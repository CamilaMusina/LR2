#include <iostream>
#include "Vector.h"
using namespace std;
	

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите значение n элементов массива ";
	cin >> n;

	double* m = new double [n];
	cout << "Введите значения массива типа Vector размерности n " << endl;
	for (int i = 0; i < n; i++)
		cin >> m[i];

	Vector V1(m, n); 
	
	double* q = new double[n];
	cout << "Введите значения массива размерности n" << endl;
	for (int i = 0; i < n; i++)
		cin >> q[i];

	Vector V2;
	V2 = q * V1;

	cout << V2;
	
	return 0;
}
