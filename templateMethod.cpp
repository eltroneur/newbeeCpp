// templateMethod.cpp -- reload templateMethod
#include <iostream>

// Singular template parameter
template <class T>
void print(T x, T y)
{
  std::cout << x << " " << y << std::endl;
}

// Dual template parameter
template <class T, class M>
void print(T x, M y)
{
  std::cout << x << " and " << y << std::endl;
}

int main()
{
  print(4, 8);
  print("Me", 18);

  return 0;
}
