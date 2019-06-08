// arrayInit.cpp -- Init an array
#include <iostream>
#include <stdio.h>

int main()
{
  int arr[3] = {1};  // first elemet of arr is 1, the rest set to 0
  int newArr[4] {2, 5, 8, 1};

  unsigned int counts[10] = {25, 92, 3.0};  // (Warning:) narrowing conversion from double to unsigned int
  unsigned int debets[10] {};  // all undefined values

  return 0;
}
