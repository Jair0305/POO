#include "intbase.hpp"

void IntBase::dec(char* str)
{
  sprintf(str, "%u", num);
}

void IntBase::bin(char* str)
{
  std::uint32_t mask = 1;

  str[32] = 0;
  for(int i = 31; i>=0; i-=1)
  {
    if (mask & num) str [i] = '1';
    else str[i] = '0';
    mask <<= 1;
  }

}

void IntBase::hex(char* str)
{
  char hexlut[] = "0123456789ABCDEF";
  //hexlut[5] = '5'
  std::uint32_t mask = 0x0000000F;

  std::uint32_t cnum = num;

  str[8] = 0;
  for( int i = 7; i>=0 ; i-=1)
  {
    unsigned n = mask & cnum;
    str[i] = hexlut[n];
    cnum = cnum >> 4;
  }

}

void IntBase::oct(char* str)
{
  //char octlut[] = "01234567";
  std::uint32_t mask = 0x00000007;

  std::uint32_t cnum = num;

  str[11] = 0;
  for( int i = 10; i>=0 ; i-=1)
  {
    unsigned n = mask & cnum;
    //str[i] = octlut[n];
    str[i] = '0' + n;
    cnum = cnum >> 3;
  }
}
