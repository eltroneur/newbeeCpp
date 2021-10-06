#include <iostream>

class Obj
{
public:
  void print() { std::cout << "count = " << count << std::endl; }

private:
  static int count;
  
};

int Obj::count = 3;

int main()
{
  Obj o;
  o.print();
  return 0;
}
