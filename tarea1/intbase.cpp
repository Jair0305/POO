#include <iostream>
#include "intbase.hpp"

using namespace std;

void IntBase::dec( char* string )
{
  int numero = 0, aux = num, posicion, numero2 = 0;
	while(aux > 0)
  {
		aux /= 10;
		numero++;
	}
	string[numero] = '\0';
	aux = num;
	posicion = numero - 1;
	while (posicion >= 0)
  {
		numero2 = aux % 10;
		aux /= 10;
		string[posicion] = numero2 + '0';
		posicion--;
	}
}

void IntBase::bin( char* string )
{
  int aux = num, numero = 0, posicion, numero2 = 0;
	while(aux > 0)
  {
	  aux /= 2;
	  numero++;
	}
	string[numero] = '\0';
	aux = num;
	posicion = numero - 1;
	while (posicion >= 0)
  {
		numero2 = aux % 2;
		aux /= 2;
		string[posicion] = numero2 + '0';
		posicion--;
	}
}

void IntBase::oct( char* string )
{
 int aux = num, numero = 0, posicion, numero2 = 0;
 while(aux > 0)
 {
 	 aux /= 8;
	 numero++;
 }
 string[numero] = '\0';
 aux = num;
 posicion = numero-1;
 while (posicion >= 0)
 {
	 numero2 = aux % 8;
	 aux /= 8;
	 string[posicion] = numero2 + '0';
	 posicion--;
 }
}

void IntBase::hex( char* string )
{
 int aux = num, numero = 0, posicion, numero2 = 0;
 while(aux > 0)
 {
	 aux /= 16;
	 numero++;
 }
 string[numero] = '\0';
 aux = num;
 posicion = numero-1;
 while (posicion >= 0)
 {
 	numero2 = aux % 16;
 	aux /= 16;
       if (numero2 > 9)
       {
           if (numero2==10)string[posicion] = 'A';
           else if (numero2==11)string[posicion] = 'B';
           else if (numero2==12)string[posicion] = 'C';
           else if (numero2==13)string[posicion] = 'D';
           else if (numero2==14)string[posicion] = 'E';
           else if (numero2==15)string[posicion] = 'F';
       }
       else
       {
           string[posicion] = numero2 + '0';
       }
	  	 posicion--;
 }
}
