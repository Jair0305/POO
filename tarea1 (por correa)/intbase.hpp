#ifndef INTBASE_HPP
#define INTBASE_HPP

#include <cstdint>

struct IntBase
{
  uint32_t num;
  void dec(char* str);
  void bin(char* str);
  void hex(char* str);
  void oct(char* str);
};

#endif
