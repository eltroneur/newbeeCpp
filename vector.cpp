// vector.cpp -- using std::vector
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  std::cout << "vec.size = " << vec.size() << ", vec.capacity() = " << vec.capacity() << ", sizeof(vec) = " << sizeof vec << std::endl;

  vec.reserve(10);
  std::cout << "vec.size = " << vec.size() << ", vec.capacity() = " << vec.capacity() << ", sizeof(vec) = " << sizeof vec << std::endl;

  vec.resize(10);
  std::cout << "vec.size = " << vec.size() << ", vec.capacity() = " << vec.capacity() << ", sizeof(vec) = " << sizeof vec << std::endl;

  vec.push_back(8);
  std::cout << "vec.size = " << vec.size() << ", vec.capacity() = " << vec.capacity() << ", sizeof(vec) = " << sizeof vec << std::endl;

  std::vector<int> new_vec;
  int count = 0;

  while (new_vec.size() == new_vec.capacity() || ++count < 6)
  {
    new_vec.push_back(88);
    std::cout << "new_vec.size = " << new_vec.size() << ", new_vec.capacity() = " << new_vec.capacity() << ", sizeof(new_vec) = " << sizeof new_vec << std::endl;
  }

  getchar(); 


  return 0;
}
