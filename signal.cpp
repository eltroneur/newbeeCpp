// signal.cpp -- c++ signal
#include <iostream>
#include <csignal>
#include <unistd.h>  // needed by sleep()
#include <cstdlib>

void signalHandler(int signum)
{
  std::cout << "Interrupt signal (" << signum << ") received.\n";

  exit(signum);
}

int main()
{
  signal(SIGINT, signalHandler);

  while (1)
  {
    std::cout << "Going to sleep... " << std::endl;
    sleep(1);
  }

  return 0;
}
