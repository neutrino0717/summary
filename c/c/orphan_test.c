// A C program to demonstrate Orphan Process.
// Parent process finishes execution while the
// child process is running. The child process
// becomes orphan.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // Create a child process
    int pid = fork();

    if (pid > 0)
        printf("in parent process, pid=%d, and exit now\n", getpid());


    // Note that pid is 0 in child process
    // and negative if fork() fails
    else if (pid == 0)
    {
        printf("in child process, pid=%d, ppid=%d\n", getpid(), getppid());
        sleep(3);
        printf("in child process, pid=%d, ppid=%d, and exit now\n", getpid(), getppid());
    }

    return 0;
}
