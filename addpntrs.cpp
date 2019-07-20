// addpntrs.cpp -- pointer addition
#include <iostream>

int main()
{
  double wages[3] = {10000.0, 20000.0, 30000.0};
  short stacks[3] = {3, 2, 1};

  // Here are two ways to get the address of an array
  double *pw = wages; // name of an array = address
  short *ps = &stacks[0]; // or use address operator
  // with array element
  std::cout << "pw = " << pw << ", *pw = " << *pw << std::endl;
  pw = pw + 1;
  std::cout << "add 1 to the pw pointer:\n";
  std::cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
  std::cout << "ps = " << ps << ", *ps = " << *ps << std::endl;
  ps = ps + 1;
  std::cout << "add 1 to the ps pointer:\n";
  std::cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

  std::cout << "access two elements with array notation\n";
  std::cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " <<  stacks[1] << std::endl;
  std::cout << "access two elements with pointer notation\n";
  std::cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << std::endl;

  std::cout << sizeof(wages) << " = size of wages array\n";
  std::cout << sizeof(pw) << " = size of pw pointer\n";


  return 0;
}
