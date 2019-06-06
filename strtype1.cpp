// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <string>  // make string class available

int main()
{
  char charr1[20]; // create an empty array
  char charr2[20] = "jaguar"; // create an initialized array
  std::string str1;  // create an empty string object
  std::string str2 = "panther"; // create an initialized string

  std::cout << "Enter a kind of feline: ";
  std::cin >> charr1;
  std::cout << "Enter another kind of feline: ";
  std::cin >> str1;  // use cin for input
  std::cout << "Here are some felines:\n";
  std::cout << charr1 << " " << charr2 << " "
	    << str1 << " " << str2 // use cout for output
	    << std::endl;
  std::cout << "The third letter in " << charr2 << " is "
	    << charr2[2] << std::endl;
  std::cout << "The third letter in " << str2 << " is "
	    << str2[2] << std::endl; // use array notation

  return 0;
}
