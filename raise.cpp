// raise.cpp -- using raise(signal sig)
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <csignal>

void signalHandler(int signum)
{
  std::cout << "signal num (" << signum << ") received." << std::endl;

  //exit(signum);
}

int main()
{
  int n = 0;
  //std::cout << "sleeping..." << std::endl;

  signal(SIGINT, signalHandler);

  while (++n)
  {
    std::cout << "sleeping..." << std::endl;
    sleep(1);
    if (n == 3)
    {
      raise(SIGINT);
    }
  }
  
  return 0;
}
