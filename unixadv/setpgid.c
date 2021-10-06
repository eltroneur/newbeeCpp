#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  printf("Main process: pid=%d,ppid=%d,pgid=%d\n", getpid(), getppid(), getpgrp());
  pid_t pid;
  int wstatus;

  pid = fork();
  if (pid < 0)
  {
    perror("fork");
    exit(-1);
  } else if (pid == 0)
  {
    int iRet = 0;
    printf("Child:before setpgid:pid=%d,ppid=%d,pgid=%d\n", getpid(), getppid(), getpgrp());
    //setpgid(getpid(), getpid());
    iRet = setpgid(0, getpid());
    printf("iRet=%d\n", iRet);
    printf("Child:after setpgid:pid=%d,ppid=%d,pgid=%d\n", getpid(), getppid(), getpgrp());
    sleep(9999);
    exit(-1);
  } else
  {
    setpgid(pid, pid);
    waitpid(pid, &wstatus, 0);
  }

  return 0;
}
