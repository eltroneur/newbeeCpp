#include <iostream>
#include <stdio.h>

int main()
{
  int *str[3]; // str is an array with 3 pointers to int
  int a = 16, b = 19, c = 21;
  str[0] = &a;
  str[1] = &b;
  str[2] - &c;

  int origin[3] = {8, 16, 24};
  int (*pstr)[3] = &origin; // pstr is a pointer to an array which has 3 int elements
  (*pstr)[0] = c;
  (*pstr)[1] = b;
  (*pstr)[2] = a;

  std::cout << origin[0] << " " << origin[1] << " " << origin[2] << std::endl;

  // size of array (12)
  std::cout << "sizeof origin = " << sizeof origin << std::endl;
  // size of a pointer (8)
  std::cout << "sizeof &origin = " << sizeof &origin << std::endl;
  //char st[5] = "Hello"; // Error:Initializer-string for array of chars is too long 
  char st[6] = "Hello";
  std::cout << "st = " << st << ", &st = " << &st  << ", *st = "<< *st <<  std::endl;
  char *pst = st;
  std::cout << "pst = " << pst << ", &pst = " << &pst << ", *pst = " << *pst << std::endl;
  printf("using %%x showing st, pst:%x, %x\n", st, pst);
  printf("using %%s showing st, pst:%s, %s\n", st, pst);

  return 0;
}
