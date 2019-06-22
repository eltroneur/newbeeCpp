// cin_get.cpp -- using cin.get() & cin.getline()
#include <iostream>

int main()
{
  std::cout << "Main ..." << std::endl;
  
  std::cin.get();
  char endChar;
  std::cin >> endChar;
  std::cout << "End char is " << endChar << std::endl;
  
  return 0;
}
