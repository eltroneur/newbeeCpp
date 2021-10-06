#include <iostream>

template <int count>
class Obj
{
public:
  void print() { std::cout << "count is " << count << std::endl; }
};

int main(int argc, char *argv[])
{
  Obj<3> o;
  o.print();
  return 0;
}
