#include <iostream>

int len(const char *str)
{
  return sizeof(str);
}

int main(int argc, char *argv[])
{

  int param1, param2;
  while (0)
  {
    std::cin >> param1 >> param2;
    std::cout << param1 << "&~" << param2 << "=" << (param1 &~ param2) << std::endl;
  }

  std::cout << sizeof("mimi") << std::endl;
  std::cout << len("mimixxxxxxx") << std::endl;

  return 0;
}
