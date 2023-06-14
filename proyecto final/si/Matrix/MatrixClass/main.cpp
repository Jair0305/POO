#include <iostream>
#include "includes/matrix.hpp"

using namespace std;

int main( void ) {

	Matrix m1( 3, 3 ), m2( 3, 2 );

	cout << "Matriz 1(" << m1.getRows() << ", " << m1.getCols() << "): " << m1
	     << "Matriz 2(" << m2.getRows() << ", " << m2.getCols() << "): " << m2;

	m1.randomMatrix();
	cout << "Matriz 1: " << m1;

	m2.randomMatrix();
	cout << "Matriz 2: " << m2;

	Matrix m3( 3, 3 );
	m3.randomMatrix();
	cout << "Matriz 1(" << m1.getRows() << ", " << m1.getCols() << "): " << m1
	     << "Matriz 2(" << m2.getRows() << ", " << m2.getCols() << "): " << m2
	     << "Matriz 3(" << m3.getRows() << ", " << m3.getCols() << "): " << m3;

	Matrix m4 = m1.inv(), m5 = m1.mult(m3);
	cout << "Matriz 4(" << m4.getRows() << ", " << m4.getCols() << ") (inversa de m1): " << m4;

	m4 = m2.inv();
	cout << "Matriz 4(" << m4.getRows() << ", " << m4.getCols() << ") (inversa de m2): " << m4;

	m4 = m3.inv();
	cout << "Matriz 4(" << m4.getRows() << ", " << m4.getCols() << ") (inversa de m3): " << m4;
	cout << "Matriz 5(" << m5.getRows() << ", " << m5.getCols() << ") (mult. de Hadamard de m1 y m3): " << m5;


	return 0;
}
