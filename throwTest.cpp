// throwTest.cpp -- using exception
#include <iostream>

double division(int a, int b)
{
  if (b == 0)
  {
    throw "division by zero Exception";
  }

  return a/b;
}

int main()
{
  int x = 50;
  int y = 0;
  double z = 0;

  std::cout << "lala" << std::endl;

  try
  {
    z = division(x, y);
    std::cout << z << std::endl;
  }
  catch(const char *msg) 
  {
    std::cerr << msg << std::endl;
  }

   return 0;
}
