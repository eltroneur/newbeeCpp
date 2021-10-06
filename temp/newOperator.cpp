#include <iostream>

int main(int argc, char *argv[])
{
  int *pI = std::new int;
  *pI = 33;
  
  delete pI;

  return 0;
}
