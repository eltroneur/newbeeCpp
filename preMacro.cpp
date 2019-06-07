// preMacro.cpp -- using pre-defined MACRO
#include <iostream>

int main()
{
  std::cout << "Current line is " << __LINE__ << std::endl;
  std::cout << "Current filename is " << __FILE__ << std::endl;
  std::cout << "Current date is " << __DATE__ << std::endl;
  std::cout << "Current time is " << __TIME__ << std::endl;

  return 0;
}
