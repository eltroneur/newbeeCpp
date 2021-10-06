#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void do_print_id(int id)
{
  std::unique_lock<std::mutex> lck(mtx);
  while (!ready) // 当前线程被阻塞，当全局标志位编程trueh之后，线程被唤醒，继续向下执行
    cv.wait(lck);
  std::cout << "thread " << id << '\n';
}

void go()
{
  std::unique_lock<std::mutex> lck(mtx);
  ready = true;
  cv.notify_all(); // wake up all threads
}

int main()
{
  std::thread threads[10];
  // spawn 10 threads
  for (int i = 0; i < 10; ++i)
  {
    threads[i] = std::thread(do_print_id, i);
  }
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "10 threads ready to race...\n";
  go();

  for (auto &thd : threads)
    thd.join();


  return 0;
}
