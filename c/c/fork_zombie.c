#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  pid_t child_pid;
  child_pid = fork();
  if (child_pid >0) {   //parent
    printf("in parent process, run ps -ef wwf |sed -n '1p;/%d/,+2p', and sleep 60 now\n", getpid());    
    sleep (60);
  }else{                //child
    exit (0);
  }
  return 0;
}
/* a zombie process or defunct process is a process that has completed execution (via the exit system call) but still has an entry in the process table: it is a process in the "Terminated state". This occurs for child processes, where the entry is still needed to allow the parent process to read its child's exit status: once the exit status is read via the wait system call, the zombie's entry is removed from the process table and it is said to be "reaped". A child process always first becomes a zombie before being removed from the resource table. In most cases, under normal system operation zombies are immediately waited on by their parent and then reaped by the system – processes that stay zombies for a long time are generally an error and cause a resource leak.*/
