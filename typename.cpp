// typename.cpp -- using keyword "typename"
#include <iostream>

template <typename T>
inline T const& Max(T const& a, T const& b)
{
  return a > b? : a, b;
}

class MyArray
{
public:
  typedef int array_type[10]; // array_type is a typename means a int array with length 10
  typedef int Coord;
};

int main()
{
  char a = 'X';
  char b = 'N';
  
  std::cout << "Max of a & b is " << Max(a, b) << std::endl;

  typedef MyArray::array_type real_array;
  typedef MyArray::Coord myCoord;

  myCoord coord = 10;

  MyArray::array_type arr;
  for (int i = 0; i < 10; ++i)
  {
    arr[i] = i*i;
  }

  for (int i = 0; i < 10; ++i)
  {
    std::cout << "arr[" << i << "] = " << arr[i] << " ";
  }

  return 0;
}
