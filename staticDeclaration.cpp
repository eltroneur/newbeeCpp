// staticDeclaration.cpp -- using static declaration
#include <iostream>
#define _GLIBCXX_DEBUG

int main()
{
  int flag;
  flag = 1;
  if ( (bool)flag )
  {
	  flag = 2;
    static int neverland[5] = { 68, 69, 88, 89, 103};
    int *new_neverland = new int[5];
    new_neverland[0] = 78;
    new_neverland[1] = 88;
    new_neverland[2] = 98;
    new_neverland[3] = 100;
  }

  std::cout << "using static declaration..." << std::endl;

  return 0;
}
