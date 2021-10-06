#include <iostream>

int round(int base, int num)
{ return ((num + base - 1) & ~(base - 1)); }

int main()
{
  int base, num;
  while (true)
  {
    std::cin >> base >> num;
    std::cout << round(base, num) << std::endl;
    
  }

  return 0;

}
