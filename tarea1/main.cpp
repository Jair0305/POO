#include <iostream>
#include "intbase.cpp"

using namespace std;

int main ()
{
	IntBase num;
	char cad[1000];

	cout<<"Ingresa el numero que quiere convertir: ";
	cin>>num.num;

  num.dec(cad);
  cout<<"\nSu numero: "<<num.num<<". Convertido a decimal es: "<<cad<<endl;;

  num.bin(cad);
  cout<<"\nSu numero: "<<num.num<<". Convertido a binario es: "<<cad<<endl;

  num.oct(cad);
  cout<<"\nSu numero: "<<num.num<<". Convertido a octal es: "<<cad<<endl;

  num.hex(cad);
  cout<<"\nSu numero: "<<num.num<<". Convertido a hexadecimal: "<<cad<<endl;

	return 0;
}
