// define.cpp -- using #define
#include <iostream>

#define PI 3.14159
#define MIN(a, b) (a < b ? a : b)

int main()
{
  int PIWOSHI = 0;
  std::cout << "Value of PI is " << PI << std::endl;

  std::string str1("Hello");
  std::string str2("World");
  int x = 10;
  
  std::cout << "MIN is " << MIN(str1, str2) << std::endl;
  //std::cout << "(conv)MIN is " << MIN(str1, x) << std::endl; // no match for operator< (std::string, int)

  return 0;
}
