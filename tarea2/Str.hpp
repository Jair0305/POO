#ifndef _STRING_HPP
#define _STRING_HPP

#include <iostream>

using namespace std;

class String
{
public:
  String();
  String(char *cadena);
  ~String();
  size_t size()const;
  void print()const;
  String(const String& copy);
  String& operator =(const String& receive);
  char& operator [](size_t index);
  bool operator ==(String const& equals) const;
  bool operator !=(String const& diferent) const;
  friend std::ostream& operator <<(std::ostream& os, const String& element);
private:
  size_t m_size;
  char *m_str;
};

std::ostream& operator <<(std::ostream& os, const String& element);

#endif
