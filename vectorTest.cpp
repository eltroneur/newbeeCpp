// vectorTest.cpp -- using vector
#include <iostream>
#include <vector>
#include <iterator>  // needed by std::ostream_iterator
#include <algorithm> // needed by std::find

int main()
{
  std::vector<char> len {'l', 'e', 'o', 'v', 'o'};
  std::copy(len.begin(), len.end(), std::ostream_iterator<char>(std::cout, ""));
  std::cout << std::endl;
  
  std::cout << "missing a \'n\', I will fix it." << std::endl;
  auto pos = std::find(len.begin(), len.end(), 'e');
  std::cout << "*pos is " << *pos << std::endl;
  ++pos;
  auto result = len.insert(pos, 'n');  // insert 'n' in the position of lb
  std::cout << "*result = " <<  *result << std::endl;
  if (result == len.end())
  {
	  std::cout << "result == len.end()" << std::endl;
  }

  std::copy(len.begin(), len.end(), std::ostream_iterator<char>(std::cout, ""));

  return 0;
}
