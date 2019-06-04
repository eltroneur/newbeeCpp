// myException.cpp -- subException class
#include <iostream>
#include <exception>

struct myException : public std::exception
{
  const char *what() const throw()
  {
    return "This is my Exception";
  }

};

int main()
{
  try
  {
    throw myException();
  }
  catch(myException &e)
  {
    std::cout << "myException caught" << std::endl;
    std::cout << e.what() << std::endl;
  }
  catch(std::exception &e)
  {
    // other Exceptions
  }

  return 0;
}
