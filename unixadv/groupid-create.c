#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  pid_t group1, group2;
  int iRet;
  
  // 创建进程组1，父进程作为组长进程
  iRet = setpgid(getpid(), getpid());
  if (iRet)
  {
    // on success, setpgid() return 0, otherwise -1.
    perror("setpgid()");
    exit(-1);
  } else
  {
    // or getpgid(0)
    group1 = getpgid(getpid());

    printf("Current PID=%d, PGID=%d\n", getpid(), group1);
    
    pid_t pid;
    int i = 0;
    for (; i < 3; ++i)
    {
      pid = fork();
      printf("aaa\n");
      if (pid < 0)
      {
        perror("fork");
        exit(-1);
      }

      if (pid == 0)
      {
        // child process
        if (i == 0)
        {
          setpgid(getpid(), getpid());
          group2 = getpgid(getpid());
        }

        if (i == 1)
        {
          setpgid(getpid(), group2);
        }

        if (i == 2)
        {
          setpgid(getpid(), group1);
        }

        //break;
      } else
      {
        // parent process
        if (i == 0)
        {
          iRet = getpgid(getpid());
          iRet = setpgid(pid, pid);
          group2 = getpgid(pid);
        }
        if (i == 1)
        {
          setpgid(pid, group2);
        }
        if (i == 2)
        {
          setpgid(pid, group1);
        }
      }
    }
  }
  printf("pid: %d, ppid: %d, pgid: %d\n", getpid(), getppid(), getpgid(0));
  pause();
  

  return 0;
}
