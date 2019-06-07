// preprocessor.cpp -- using Preprocessor
#include <iostream>

#define DEBUG

#define MIN(a, b) a < b ? : a, b

int main()
{
  int i, j;
  i = 100;
  j = 30;

#ifdef DEBUG
  std::cerr << "Trace: Inside main function" << std::endl;
#endif

#if 0
  // this is the comment part
  cout << MKSTR(HELLO C++ ) << std::endl;
  I am not a C++ sentense
#endif

  return 0;
}
