#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t pid;
  int mypipefd[2];
  char buf[20];
  int ret;

  ret = pipe(mypipefd);
  if(ret == -1){
    perror("pipe");
    exit(1);
  }

  pid = fork();
  if(pid == 0){
    /*child process*/
    printf("child process\n");
    close(mypipefd[0]);
    write(mypipefd[1], "hello there!", 12);  //1 is for write

  } else {
    /*parent prcess*/
    printf("parent prcess\n");
    close(mypipefd[1]);
    read(mypipefd[0], buf, 15);    //0 is for read
    printf("buf: %s\n", buf); 
  }

  

  return 0;
}
