#include <iostream>
#include <cstdlib>
#include <cctype>

int main()
{
  std::cout << "Select the mode of detection: \n";
  std::cout << " N/n to use New mode, O/o to use Old mode\n";
  char input;
  std::cin >> input;
  // 'CTRL+Z' may force stop the program(in MAC OS)
  // so this detection may be useless
  if (std::cin.eof())
  {
    std::cout << "EOF dectected, exit the program.\n";
    exit(-1);
  }
  if ('o' == input || 'O' == input)
  {
    // old 
    while (std::cin >> input)
    { // '&&' is prior than '||' so this judgement was file
      // but clang in MacOS may warn "place parentheses around the '&&'"
      if (input >= 'a' && input <= 'z' || input >= 'A' && input <= 'Z')
      {
        std::cout << "gets a char type\n";
      }
      else if (input >= '1' && input <= '9')
      {
        std::cout << "gets a integer\n";
      }
      else
      {
        std::cout << "not a char or a number\n";
      }
    }
  }
  else
  {
    // new
    while (std::cin >> input)
    {
      // TODO: EOF detection
      if (isalpha(input))
      {
        std::cout << "gets a char type\n";
      }
      else if (isdigit(input))
      {
        std::cout << "gets a integer\n";
      }
      else
      {
        std::cout << "not a char or a number\n";
      }
    }
  }

  return 0;
}
