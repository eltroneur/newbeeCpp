// detach.cpp 
#include <iostream>
#include <thread>

void function_1()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "I'm function_1()" << std::endl;
}

void test()
{
  std::thread t1(function_1);
  t1.detach();
  //t1.join();
  std::cout << "test() finished" << std::endl;
}

int main()
{
  test();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  return 0;
}
