// lrshift.cpp -- using << & >> (left shift and right shift)
#include <iostream>
#include <bitset>

int main()
{
  // unsigned left-shifted
  unsigned short short1 = 4;
  std::bitset<16> bitset1{short1}; // the bitset representation of 4
  std::cout << bitset1 << std::endl; // 0000000000000100

  unsigned short short2 = short1 << 2; // 4 left-shifted by 2 = 16
  std::bitset<16> bitset2{short2};  // using -std=c++11
  std::cout << bitset2 << std::endl; // 000000000010000

  unsigned short short4 = short1 >> 1; // 4  right-shifted by 1 = 2
  std::bitset<16> bitset4(short4); // 0000000000000010
  std::cout << bitset4 << std::endl; 

  return 0;
}
