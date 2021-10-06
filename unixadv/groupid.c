#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    printf("start fork......\n");
    if ( (pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    } else if (pid == 0)
    {
        /* or you can repleace "getpgrp()" with getpgid(getpid()) */
        printf("This is child process, pid=%d,group-id=%d,session-id=%d\n", getpid(), getpgrp(), getsid(0));
        setpgid(getpid(), getpid());
        printf("Child: after setgpid, pid=%d,pgid=%d,session-id=%d\n", getpid(), getpgrp(), getsid(0));
        exit(1);
    } else
    {
        wait(NULL);
        printf("Parent: Children exited.\n");
        printf("This is parent process, pid=%d,group-id=%d,session-id=%d\n", getpid(), getpgrp(), getsid(0));
    }
    
    return 0;
}
