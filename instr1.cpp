// instr1.cpp -- reading more than one string
#include <iostream>

int main()
{
  const int ArSize = 20;
  char name[ArSize];
  char dessert[ArSize];

  std::cout << "Enter your name:\n";
  std::cin >> name;
  std::cout << "Enter your favorite dessert:\n";
  std::cin >> dessert;
  std::cout << "I have some delicious " << dessert;
  std::cout << " for you, " << name << ".\n";

  return 0;
}
