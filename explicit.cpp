// explicit.cpp -- using keyword explicit
#include <iostream>
#include <cstring>
#include <malloc.h>

class CxString // If no explicit declared, implicit declaraction used
{
public:
  char *_pstr;
  int _size;
  CxString(int size)
  {
    _size = size;
    _pstr = (char *)malloc(size + 1);
    memset(_pstr, 0, size + 1);
  }

  CxString(const char *p)
  {
    int pSize = strlen(p);
    _size = pSize;
    _pstr = (char *)malloc(_size + 1);
    strcpy(_pstr, p);
  }
  
  void showSize()
  {
    std::cout << "My size is " << _size << " bytes." << std::endl;
    std::cout << "And content is " << _pstr << std::endl;
  }

  // no destructor...
};

class CxString_exp
{
public:
  char *_pstr;
  int _size;
  explicit CxString_exp(int size)
  {
    _size = size;
    _pstr = (char *)malloc(size + 1);
    memset(_pstr, 0, size + 1);
  }

  CxString_exp(const char* p)
  {
    int pSize = strlen(p);
    _size = pSize;
    _pstr = (char *)malloc(_size + 1);
    strcpy(_pstr, p);
  }

  void showSize()
  {
    std::cout << "my Size is " << _size << std::endl;
    std::cout << "And content is" << _pstr << std::endl;
  }
  
};

int main()
{
  CxString string1(24); // fine
  string1.showSize();
  CxString string2 = 10; // fine, a obj with 10 bytes
  string2.showSize();

  CxString string3("Hello Explicit!");
  string3.showSize();

  CxString string4 = "Shit is delicious!";  // fine, a obj with 18 bytes
  string4.showSize();

  CxString_exp exp1(88); // fine
  exp1.showSize();

  //CxString_exp exp2 = 9; // Error! Invalid conversion from 'int' to 'const char *'

  return 0;
}
