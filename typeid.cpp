// typeid.cpp -- using std::typeid
#include <iostream>

class Base{};
class Derived : public Base {};

int main()
{
  Base b, *pb = NULL;
  Derived d;
  
  std::cout << typeid(int).name() << std::endl
  << typeid(unsigned).name() << std::endl
  << typeid(long).name() << std::endl
  << typeid(char).name() << std::endl
  << typeid(unsigned char).name() << std::endl
  << typeid(float).name() << std::endl
  << typeid(double).name() << std::endl
  << typeid(std::string).name() << std::endl
  << typeid(Base).name() << std::endl
  << typeid(b).name() << std::endl
  << typeid(pb).name() << std::endl
  << typeid(Derived).name() << std::endl
  << typeid(d).name() << std::endl
  << typeid(std::type_info).name() << std::endl;


  return 0;
}
