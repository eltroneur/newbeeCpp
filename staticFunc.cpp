// staticFunc.cpp -- using static function
#include <iostream>

class Point
{
public:
  void init()
  {
    std::cout << "total count is " << count << std::endl; // fine, non-static function use static member variable
    output(); // fine, non-static function call static method
  }

  static void output()
  {
   std::cout << "Output from Point:" << std::endl;
   //std::cout << "Type is " << type << std::endl; // error! invalid use of member 'Point::type' in static member function
   //init(); // Error: cannot call member function 'void Point::init()' without object
  }

//private: // error! 'Point::count' is private within this context
  static int count;

private:
  int type;

};

int Point::count = 8;

int main()
{
  //Point::init(); // error! cannot call member function 'void Point::init()' without object
  Point::output(); // fine
  std::cout << ++Point::count << std::endl;

  static Point p1; // this static does not affect anything
  p1.init();
  p1.output(); // a obj may call both static member or non-static
  std::cout << "count of p1 is " << p1.count << std::endl;
  //std::cout << "count of p1 is " << p1::cout << std::endl; // error! 'p1' is not a class, namespace or enumeration

  return 0;
}
