#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 5 

int main(int argc, char *argv[])
{
  int n;
  char buf[BUFFSIZE];
  
  printf("STDIN_FILENO=%d,STDOUT_FILENO=%d,STDERR_FILENO=%d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);

  while ( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
  {
    printf("n=%d\n", n);
    if (write(STDOUT_FILENO, buf, n) != n)
    {
      printf("write error\n");
      exit(-1);
    }
  }

  printf("at end, n=%d\n", n);

  return 0;
}
