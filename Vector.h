#pragma once
#include<iostream>
using namespace std;

class Vector
{
	double* p; // ��������� �� ������ (������)
	int n; // ����������� ������� (����� ���������) �������

public:
	Vector(double* p, int n);
	Vector(const Vector& V);
	Vector(Vector&& V);
	Vector();
	double& operator[](int index);
	Vector& operator =(Vector& v2);
	friend ostream& operator <<(ostream& out,Vector& vector);
	~Vector();
	friend Vector& operator*(double* x, Vector& vector);
};

