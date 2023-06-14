#include <iostream>
#include "intbase.cpp"

using namespace std;

int main()
{
  IntBase obj;
  obj.num = 185;
  char string[33];

  obj.dec(string);
  cout << "dec = " << string << endl;

  obj.bin(string);
  cout << "bin = " << string << endl;

  obj.hex(string);
  cout << "hex = " << string << endl;

  obj.oct(string);
  cout << "oct = " << string << endl;

}
