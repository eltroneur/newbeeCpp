// std_copy.cpp -- using std::copy
#include <iostream>
#include <vector>
#include <iterator>  // needed by std::ostream_iterator<>

int main()
{
  std::vector<char> vec_char {'O', 'n', 'e', 'p', 'l', 'u', 's'};
  std::copy(vec_char.begin(), vec_char.begin() + 4, std::ostream_iterator<char>(std::cout, ""));  // an easy way to traverse the vector
  std::cout << std::endl;

  //std::cout << vec_char << std::endl; // no operator <<

  return 0;
}
