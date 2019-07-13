// arrAddr.cpp -- address of array
#include <iostream>

int main()
{
  short int storage[3] = {7, 4, 8};
  // same as &storage[0], means address of first element
  std::cout << "storage = " << storage << std::endl;
  // means address of whole array
  std::cout << "&storage = " << &storage << std::endl;
  std::cout << "&storage[0] = " << &storage[0] << std::endl;

  // added sizeof int (2)
  std::cout << "storage + 1 = " << storage + 1 << std::endl;
  // added sizsof whole array (6)
  std::cout << "&storage + 1 = " << &storage + 1 << std::endl;
  // added sizeof int (2)
  std::cout << "&storage[0] + 1  = " << &storage[0] + 1 << std::endl;

  /*
  if (storage == &storage)  // Error: comparision between distinct pointer type short int* and short int (*)[3] lacks a cast
  {
    std::cout << "storage == &storage" << std::endl;
  }
  else
  {
    std::cout << "storage != &storage" << std::endl;
  }
  */
  return 0;
}
