#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "../includes/matrix.hpp"

using std::setw;
using namespace std;

Matrix::Matrix() { 
	m = 1;
	n = 1;
	elemPtr = new double[1];
	elemPtr[0] = 0.0;	
}

// Constructor paramétrico y por defecto de la clase.
Matrix::Matrix( int nRen, int nCol ) {
	m = ( nRen > 0 ) ? nRen : 1;
	n = ( nCol > 0 ) ? nCol : 1;

	// Creamos el arreglo que contendrá todos los elementos de la matriz.
	elemPtr = new double[ n*m ];

	// Verificamos si se pudo crear correctamente.
	assert( elemPtr != 0 );

	// Si no se detuvo el programa, inicializamos en ceros la matriz.
	for( int i = 0; i < ( m*n ); i++ ) elemPtr[ i ] = 0.0;
}

Matrix::Matrix( int nRen, int nCol, double *vec ) : Matrix( nRen, nCol ) {
	for( int i = 0; i < (m*n); i++ ) elemPtr[i] = vec[i];
}

// Constructor copia: Crea matriz a partir de otra.
Matrix::Matrix( const Matrix &matrix ) : Matrix( matrix.m, matrix.n ) {
	// Copiamos los elementos de la matriz a copiar en la nueva.
	for( int i = 0; i < ( m*n ); i++ ) elemPtr[i] = matrix.elemPtr[i];
}

// Destructor, libera la memoria almacenada con new.
Matrix::~Matrix() {
	delete [] elemPtr;
}

// Funciones miembro.
	// Inversa de una matriz.
const Matrix Matrix::inv() const {

	// Si la matriz es cuadrada, devuelve la inversa, en caso contrario, devuelve simplemente la matriz original.
	if( this->m == this->n ) {
		// Creamos matriz aumentada [matrix original | inversa].
		Matrix temp( this->m, 2*(this->n) );

		// Copiamos la matriz original en la aumentada.
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < n; j++ )
				temp( i, j ) = (*this)(i, j);
		
		// Creamos la inversa.
		for( int i = 0; i < m; i++ ) temp( i, 2*(n-1)+(i-1) ) = 1;

		// Método de Gauss para hacer la matriz original en escalonada.
		for( int i = 0; i < temp.m; i++ ) {
			temp.multRenglon( i, 1/temp(i, i) ); 
			for( int j = 0; j < temp.m; j++ ) if( j != i ) temp.sumRen( j, i, -temp( j, i) );
		}

		// Copiamos la matriz resultante en una nueva para devolverla.
		Matrix res( this->m, this->n );
		for( int i = 0; i < res.m; i++ )
			for( int j = 0; j < res.n; j++ )
				res( i, j ) = temp( i, 2*(this->n-1)+(j-1) );

		return res;
	} 

	return *this;
}

void Matrix::multRenglon( int ren, double cte ) {
	for( int i = 0; i < this->n; i++ ) (*this)( ren, i ) *= cte;
}

void Matrix::sumRen( int dest, int src, double cte) {
	for( int i = 0; i < this->n; i++ ) {
		(*this)( dest, i ) += cte*(*this)( src, i );
	}
}

	// Multiplicación de Hadamard.
const Matrix Matrix::mult( const Matrix &right ) const {

	// Si las matrices tienen las mismas dimensiones.
	if( (this->m == right.m) && (this->n == right.n) ) {
		Matrix res( this->m, this->n );
		for( int i = 0; i < res.m; i++ )
			for( int j = 0; j < res.n; j++ )
				res( i, j ) = (*this)(i, j)*right(i, j);

		return res;
	}

	return *this;
}

	// Rellena la matriz con valores (enteros) aleatorios.
void Matrix::randomMatrix() {
	for( int i = 0; i < ( m*n ); i++ ) elemPtr[i] = ranNum( 0, 100 );
}

// Funciones utilitarias.
int Matrix::ranNum( int min, int max ) { return ( rand()%max ) + min; }

// Operadores sobrecargados.
	// Operador de asignación.
const Matrix &Matrix::operator =( const Matrix &right ) {

	// Para evitar autoasignación.
	if( &right != this ) {
		delete [] elemPtr;
		m = right.m; n = right.n;

		elemPtr = new double[ m*n ];
		for( int i = 0; i < ( m*n ); i++ ) elemPtr[i] = right.elemPtr[i];
	}

	return *this;
}

	// Operador de adición.
const Matrix Matrix::operator +( const Matrix &right ) {
	Matrix res;
	
	// Si la matriz tiene las mismas dimensiones se realiza la operación.
	if( m == right.m && n == right.n ) {
		res.m = m; res.n = n;
		if( res.elemPtr ) delete [] res.elemPtr;

		res.elemPtr = new double [ res.m*res.n ]; 
		for( int i = 0; i < ( m*n ); i++ )
			res.elemPtr[i] = elemPtr[i] + right.elemPtr[i];
	}

	return res;
}

const Matrix Matrix::operator -( const Matrix &right ) {
	Matrix res;

	// Si la matriz tiene las mismas dimensiones se realiza la operación.
	if( m == right.m && n == right.n ) {
		res.m = m; res.n = n;
		if( res.elemPtr ) delete [] res.elemPtr;

		res.elemPtr = new double [ res.m*res.n ]; 
		for( int i = 0; i < ( m*n ); i++ )
			res.elemPtr[i] = elemPtr[i] - right.elemPtr[i];
	}

	return res;
}

const Matrix Matrix::operator *( const Matrix &right ) {
	Matrix res;

	// Verificamos si las matrices son multiplicables.
	if( n == right.m ) {
		res.m = (*this).m; res.n = right.n;
		if( res.elemPtr ) delete [] res.elemPtr;

		res.elemPtr = new double[ res.m*res.n ];
		
		for( int i = 0; i < res.m; i++ )
			for( int j = 0; j < res.n; j++ )
				for( int k = 0; k < n; k++ )
					res(i, j) += (*this)(i, k)*right(k, j);
	}

	return res;
}

// Verificar que no se pase del límite de elementos.
double &Matrix::operator ()( int x, int y ) {
	if( x <= m && y <= n )
		return elemPtr[ x*n + y ];
	return elemPtr[0];
}
const double Matrix::operator ()( int x, int y ) const {
	if( x <= m && y <= n )
		return elemPtr[ x*n + y ];
	return elemPtr[0];
}

// Operador << sobrecargado, muestra la matriz en pantalla en formato cuadriculado.
ostream &operator <<( ostream &output, const Matrix &matrix ) {
	// Imprime cada elemento del arreglo en formato cuadrado con salto cada n+1 elementos.
	output << endl;
	for( int i = 0; i < ( matrix.m*matrix.n ); i++ )
		output << setw( 12 ) << matrix.elemPtr[ i ] << ( ( (i+1)%matrix.n == 0 ) ? '\n' : ' ' );
	output << endl;

	return output;
}

// Operador >> sobrecargado, permite introducir una matriz.
istream &operator >>( istream &input, Matrix &matrix ) {
	cout << endl;
	for( int i = 0; i < matrix.m; i++ ) {
		for( int j = 0; j < matrix.n; j++ ) {
			cout << "Elemento [" << i << ", " << j << "] = ";
			input >> matrix.elemPtr[ (i*matrix.n) + j ];
		}
	}
	cout << endl;

	return input;
}
