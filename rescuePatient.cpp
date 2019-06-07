// rescuePatient.cpp -- using std::thread to rescue a patient
#include <iostream>
#include <thread>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

volatile int organTime[3][2] = {0};
volatile static int tic_tok = 0;

void partRescue(int i)
{
  std::cout << "Rescuing organ " << i << std::endl;
  for (int j = 0; j < organTime[i][0]; ++i)
  {
    sleep(1);
    ++tic_tok;
  }
  organTime[i][1] = 1;
}

void judge()
{
  while (tic_tok < 10)
  {
    if (organTime[0][1] && organTime[1][1] && organTime[2][1])
    {
      std::cout << "Congratulations! Alive!" << std::endl;
      exit(1);
    }
    sleep(1);
  }
  std::cout << "We sorry about that! Waste!" << std::endl;
  exit(-1);
}

int main()
{
  srand((unsigned)time(NULL));
  for (int i = 0; i < 3; ++i)
  {
    organTime[i][0] = 1 + rand()%5;
  }
  
  std::thread t1(partRescue, 0);
  std::thread t2(partRescue, 1);
  std::thread t3(partRescue, 2);

  t1.join();
  t2.join();
  t3.join();

  judge();
  //sleep(15);

  return 0;
}
