#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

using std::ostream;
using std::istream;

class Matrix {

	friend ostream &operator <<( ostream &, const Matrix & );
	friend istream &operator >>( istream &, Matrix & );
	
	public:
		Matrix(); // Constructor por defecto.
		Matrix( int, int ); // Constructor paramétrico.
		Matrix( int, int, double * ); // Constructor que copia los datos desde un vector.
		Matrix( const Matrix & ); // Constructor copia.
		~Matrix(); // Destructor.

		// Funciones miembro.
		int getRows() const { return m; }
		int getCols() const { return n; }
		int getSize() const { return m*n; }

		const Matrix  inv() const; // Inversa de una matriz.
		const Matrix mult( const Matrix & ) const; // Multiplicación de Hadamard.

		void randomMatrix();

		// Operadores sobrecargados.
		const Matrix &operator =( const Matrix & ); // Operador de asignación.
		const Matrix operator +( const Matrix & );  // Operador de adición.
		const Matrix operator -( const Matrix & );  // Operador de sustracción.
		const Matrix operator *( const Matrix & );  // Operador de producto.
		const Matrix operator /( const Matrix & );  // Operador de división matricial.

		double &operator ()( int, int ); //Operador paréntesis (permite modificar un elemento).
		const double operator()( int, int ) const; // Operador paréntesis (sólo lectura).

		void multRenglon( int, double );
		void sumRen( int, int, double );

	private:
		int m; // Número de renglones de la matriz.
		int n; // Número de columnas de la matrix.
		double *elemPtr; // Apuntador a tipo double que contendrá los elementos de la matrix.

		// Función utilitaria.
		int ranNum( int, int );
};

#endif
