#include <iostream>
#include <future>
#include <chrono>

void Thread_Fun1(std::promise<int> &p)
{
  std::this_thread::sleep_for(std::chrono::seconds(5));

  int iVal = 233;
  std::cout << "setting value(int):" << iVal << std::endl;

  p.set_value(iVal);
}

void Thread_Fun2(std::future<int> &f)
{
  // blocking call, until the linking std::promise reseives value
  auto iVal = f.get();

  std::cout << "Receiving value is:" << iVal << std::endl;
}

int main()
{
  std::promise<int> pr1;
  std::future<int> fu1 = pr1.get_future();

  std::thread t1(Thread_Fun1, std::ref(pr1));
  std::thread t2(Thread_Fun2, std::ref(fu1));

  t1.join();
  t2.join();

  return 0;
}
