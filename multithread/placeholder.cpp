#include <functional>
#include <string>
#include <iostream>

void goodbye(const std::string &s)
{
  std::cout << "Goodbye " << s << '\n';
}

class Object {
public:
  void hello(const std::string &s)
  {
    std::cout << "Hello " << s << '\n';
  }
};

// simulate default parameter
int TestFunc(int a, char c, float f)
{
  std::cout << a << std::endl;
  std::cout << c << std::endl;
  std::cout << f << std::endl;

  return a;
}

int main(int argc, char *argv[])
{
  typedef std::function<void (const std::string &s)> ExampleFunction;
  Object instance;
  std::string str("World");
  ExampleFunction f = std::bind(&Object::hello, &instance, std::placeholders::_1);

  // equivalent to instance.hello(str)
  f(str);

  typedef std::function<void (const std::string &)> funFinish;
  funFinish ff = std::bind(goodbye, std::placeholders::_1); // same as the following line
  //funFinish ff = std::bind(&goodbye, std::placeholders::_1);
  ff("charly");

  std::function<int (int, char, float)> fun1 = std::bind(TestFunc, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
  // change the order of parameter list
  auto fun2 = std::bind(TestFunc, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);
  auto fun3 = std::bind(TestFunc, std::placeholders::_1, std::placeholders::_2, 98.77);

  fun1(30, 'C', 100.1);
  fun2(100.1, 30, 'C');
  fun3(30, 'C');
  // the last param 88.8 will be ignored
  fun3(30, 'C', 88.8);

  return 0;
}
