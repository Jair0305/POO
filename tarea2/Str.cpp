#include "Str.hpp"

void String::print() const
{
    for(int i=0; i<m_size; i++)
        cout << m_str[i] ;
}

size_t String::size() const
{
    return m_size;
}

String::~String()
{
   if (m_str != nullptr)delete[] m_str;
}

String::String(char *cadena)
{
    size_t tam = 0;
    while (cadena[tam] != '\0' )
        tam++;

    m_size = tam;

    if (m_size == 0)
    return;

    m_str = new char[m_size];

    for (size_t i = 0; i < m_size; i++)
        m_str[i] = cadena[i];
}

bool String::operator ==(String const& equals) const
{
  bool value = true;
  for(size_t i=0; i<m_size; i++)
  {
    if(m_str[i] == equals.m_str[i])
    {
      continue;
      value = true;
    }
    else
    {
      value = false;
      break;
    }
  }
  return value;
}

bool String::operator !=(String const& diferent) const
{
  bool value = false;
  for(size_t i=0; i<m_size; i++){
    if(m_str[i] != diferent.m_str[i]){

      value = true;
      break;
    }
    else
    {
      value = false;
      continue;
    }
  }
  return value;
}

std::ostream& operator <<(std::ostream& os, const String& element)
{
    for(size_t k=0; k<element.m_size; k++)
        os << element.m_str[k] << ", ";

    return os;
}

String::String()
{
    m_size = 0;
    m_str = nullptr;
}

String::String(const String& copy)
{
  if(copy.m_size == 0)
  return;

  m_size = copy.m_size;
  m_str = new char[m_size];
  for(size_t i=0; i<m_size; i++)
  m_str[i] = copy.m_str[i];
}

String& String::operator =(const String& receive)
{
  if(m_str != nullptr)
  delete [] m_str;

  if(receive.m_size == 0)
  {
    m_size = 0;
    m_str = nullptr;
  }
  else
  {
    m_size = receive.m_size;
    m_str = new char[m_size];
    for(size_t i=0; i<m_size; i++)
    m_str[i] = receive.m_str[i];
  }
  return *this;
}

char& String::operator [](size_t index)
{
  if(index >= m_size)
  throw "indice fuera de rango. No existe tal elemento";

  return m_str[index];
}
