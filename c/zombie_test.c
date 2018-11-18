#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  pid_t child_pid;
  child_pid = fork();
  if (child_pid >0) {   //parent
    sleep (60);
  }else{                //child
    exit (0);
  }
  return 0;
}
