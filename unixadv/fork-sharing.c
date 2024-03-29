// a demo showing how changes to variables in a child
// do not affect the value in the parent process
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int globvar = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[])
{
  int var; /* automatic variable on the stack */
  pid_t pid;

  var = 88;
  if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != (sizeof(buf) - 1) )
  {
    perror("write error");
    exit(-1);
  }

  printf("before fork\n"); /* we don't flush stdout */
  if ( (pid = fork()) < 0 )
  {
    perror("fork");
    exit(-1);
  } else if (pid == 0) /* child */
  {
    ++globvar; /* modify variables */
    ++var;
  } else /* parent */
  {
    sleep(2);
  }

  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

  return 0;
}
