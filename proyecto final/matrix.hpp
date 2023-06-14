#ifndef MATRIX_HPP
#define INTBASE_HPP

#include <iostream>
#include <cstdint>

class Matrix
{
private:
  double m_M;
  double n_N;
  double *m_dato;
public:
  //construt
  Matrix();
  ~Matrix();
  Matrix(double M, double N);
  Matrix(double M, double N, double *dato);
};

#endif
