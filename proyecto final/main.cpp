#include <iostream>
#include "matrix.hpp"

using namespace std;

int main()
{
  double Ma, Na;

  double *elemento;
  cout<<"Cual es el número de filas que tendra la matriz";
  cin>>Ma;
  cout<<"Cual es el número de columnas que tendra la matriz";
  cin>>Na;

  Matrix A(Ma,Na);

  cout<<"Cual es el número de filas que tendra la matriz";
  cin>>Ma;
  cout<<"Cual es el número de columnas que tendra la matriz";
  cin>>Na;

  Matrix B(Ma,Na);


}
