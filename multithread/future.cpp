#include <iostream>
#include <future>

int main()
{
  std::future<int> fut = std::async(std::launch::async, [] () -> int{
		  std::this_thread::sleep_for(std::chrono::seconds(2));
		  return 99;
		  });

  std::future_status stat;
  int iRet = -1;
  do {
    stat = fut.wait_for(std::chrono::milliseconds(500));
    switch (stat)
    {
      case std::future_status::timeout:
      {
        std::cout << "timeout reached!" << std::endl;
        break;
      }
	      break;
      case std::future_status::deferred:
	      break;
      case std::future_status::ready:
      {
        iRet = fut.get(); 
        std::cout << "result ready! result = " << iRet << std::endl;
	break;
      }
    }
  } while (fut.valid());

  return 0;
}
