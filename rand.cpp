// rand.cpp -- using random number
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
  //int time = (unsigned)time(NULL);
  srand((unsigned)time(NULL));

  for (int i = 0; i < 10; ++i)
  {
    std::cout << rand() << '\t';
  }

  std::cout << std::endl;

  return 0;
}
