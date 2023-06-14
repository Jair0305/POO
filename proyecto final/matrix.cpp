#include "matrix.hpp"

using namespace std;

Matrix::Matrix()
{
	m_M = 1;
	n_N = 1;
}

Matrix::~Matrix()
{
	delete[]m_dato;
}

Matrix::Matrix(double M, double N)
{
	m_M = M;
	n_N = N;
}

Matrix::Matrix(double M, double N, double *dato)
{
	m_M = M;
	n_N = N;
	m_dato = dato;

	double* m_dato = new double[m_M*n_N];
}
