// strings.cpp -- storing strings in an array
#include <iostream>
#include <cstring> // for the strlen() function

int main()
{
  const int Size = 15;
  char name1[Size];  // empty array
  char name2[Size] = "C++owboy";  // initialized array
  // NOTE: some implementations may require the static keyword
  // to initialize the array name2
  
  std::cout << "Howdy! I'm " << name2;
  std::cout << "! What's your name?\n";
  std::cin >> name1;
  std::cout << "Well, " << name1 << ", your name has ";
  std::cout << strlen(name1) << " letters and is stored\n";
  std::cout << "in an array of " << sizeof(name1) << " bytes.\n";
  std::cout << "Your initial is " << name1[0] << ".\n";
  name2[3] = '\0';  // set to null character
  std::cout << "Here are the first 3 characters of my name: ";
  std::cout << name2 << std::endl;

  return 0;
}
