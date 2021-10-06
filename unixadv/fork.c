#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 256

int main(void)
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% "); /* print prompt (printf requires %% to print '%')*/
  while (fgets(buf, MAXLINE, stdin) != NULL)
  {
    if (buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0; /* replace newline with null */

    if ( ( pid = fork() ) < 0 )
    { 
      printf("fork error!\n");
      exit(-1);
    } else if ( pid > 0 )
    {
      printf("This is main process! pid=%d\n", getpid());
      printf("Main process created a process whose pid is %d\n", pid);
      /* parent */
      if ( (pid = waitpid(pid, &status, 0) ) < 0)
      {
        printf("waitpid() return error, errorno=%d\n", pid);
        exit(-1);
      }
      printf("waitpid() success!\n");
    } else // pid == 0
    {
      printf("This is child process, pid = %d\n", getpid());
      /* child */
      execlp(buf, "abc", (char *)0);
      printf("couldn't execute: %s\n", buf);
      exit(-1);
    }
    printf("%%");
  }

  return 0;
}
