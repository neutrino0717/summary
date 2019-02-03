#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int fd1, fd2;
  int ret;
  /*O_CREAT   creat if not exist
    O_TRUNC   truncate to 0 if exit
    O_APPEND  the file offset will be set to the end of the file prior to each write.
    O_RDWR    for both read and write*/
  fd1 = open("dup2_stdout.txt.log", O_CREAT | O_TRUNC | O_APPEND | O_RDWR, S_IRWXU | S_IRWXG | S_IROTH);
  fd2 = open("dup2_stderr.txt.log", O_CREAT | O_TRUNC | O_APPEND | O_RDWR, S_IRWXU | S_IRWXG | S_IROTH);
  if(fd1 < 0 || fd2 <0){
    perror("open");
    exit(1);
  }
/*
dup2 system calls create a copy of the file descriptor oldfd
int dup2(int oldfd, int newfd);
dup2() makes newfd be the copy of oldfd, closing newfd first
dup2() makes 1     be the copy of fd1, closing 1 first
*/
  ret = dup2(fd1, 1);  
  if(ret < 0){
    perror("dup2 out");
    exit(1);
  }
/*dup2() makes 2 be the copy of fd2, closing 2 first*/
  ret = dup2(fd2, 2);
  if(ret < 0){
    perror("dup2 out");
    exit(1);
  }

  system("ls /tmp /tmp2"); /*result: error to fd2, output to fd1*/
  close(fd1);
  close(fd2);
/*
  printf("the stdout is now in dup2_stdout.txt.log:\n");
  system("cat dup2_stdout.txt.log");
  printf("the stderr is now in dup2_stderr.txt.log:\n");
  system("cat dup2_stderr.txt.log");
*/
  return 0;
}
