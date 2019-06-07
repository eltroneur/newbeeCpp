// pound.cpp -- using '#'
#include <iostream>

#define BIU( x ) #x

#define CONCAT(x, y) x ## y

#define WHOAMI 9400

int main()
{
  std::cout << BIU(HELLO C++) << std::endl;

  std::cout << CONCAT(WHO, AMI) << std::endl;

  return 0;
}
