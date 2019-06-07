// boxArray.cpp -- box array(class array)
#include <iostream>

class Box
{
public:
  Box()
  {
    std::cout << "A new Box created!" << std::endl;
  }
  ~Box()
  {
    std::cout << "This box was destroyed!" << std::endl;
  }

};

int main()
{
  int const size = 4;
  
  Box *boxArr = new Box[size];

  delete []boxArr;

  return 0;
}
