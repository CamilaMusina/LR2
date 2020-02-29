#include "Vector.h"
#include <iostream>

//using namespace std;

Vector::Vector() // ����������� ��� ����������
{ 
	p = nullptr; 
	n = 0; 
} 

Vector::Vector(double* p, int n) // ����������, ��������� ������ ��� ������� ������ ������� n
{
	this->n = n; // ������ ����� ���������
	this->p = new double[n]; // �������� ������
	for (int i = 0; i < n; i++) this->p[i] = p[i]; // �������� ���� ������ � ������
}

Vector::Vector(const Vector& vector)
{ // ����������� �����������
	n = vector.n;
	p = new double[n];
	for (int i = 0; i < n; i++)
		p[i] = vector.p[i];
}

// ����������� �����������
Vector::Vector(Vector&& vector)  // �������� - �������������� ������
	: p(nullptr)
	, n(vector.n)   
{
	p = new double[n];
	memcpy(p, vector.p, n);
}


double& Vector::operator[](int i) 
{
	return p[i];
}
Vector& Vector::operator =(Vector& vector) // ��������- ������� ����������� ������� 
{
	n = vector.n;
	if (p != nullptr) delete[] p; // ����������� ������ ������� �������
	p = new double[n]; // �������� ������ ��� ������ �������
	for (int i = 0; i < n; i++) p[i] = vector.p[i];
	return *this; // ���������� ������ �� ������� ������
}

Vector::~Vector() // ����������
{
	if (p != nullptr) delete[] p; // ����������� ������
}

std::ostream& operator<<(ostream& out, Vector& vector)
{
	for (int i = 0; i < vector.n; i++)
		out << vector.p[i] << " ";
	out << endl;

	return out;
}


Vector& operator*(double* x, Vector& vector) {
	double* p = new double[vector.n]; // ������� ����� ������
	for (int i = 0; i < vector.n; i++) p[i] = x[i] * vector.p[i]; // ��������� ������
	Vector* pV = new Vector(p, vector.n); // ������� ����� ������ �� ������ �������
	delete[] p; // ����������� ������
	return *pV; // ���������� ������ �� ������
}
