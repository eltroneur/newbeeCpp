// thread.cpp -- using std::thread
#include <iostream>
#include <thread>
#include <unistd.h>
#include <exception>

void function_1()
{
  std::cout << "I'm function_1()" << std::endl;
  std::cout << "Sleeping..." << std::endl;
  sleep(2);
  std::cout << "Wake up!" << std::endl;
}

int main()
{
	try
	{
		std::thread t1(function_1);
		// do other things
		//t1.detach();
	
		std::cout << "Main thread exiting.." << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << "Exception:" << ex.what() << std::endl;
		exit(-1);
	}

	return 0;
}
