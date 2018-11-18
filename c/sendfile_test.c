#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int fd1, fd2;
  int ret;
  char buf[20];
  struct stat stbuf;

  if((fd1 = open("/etc/resolv.conf", O_RDONLY)) < 0) {
    perror("open() read");
    exit(1);
  }

  if((fd2 = open("resolv.txt.log", O_CREAT | O_WRONLY, 0600)) < 0) {
    perror("open() write");
    exit(1);
  }
  /*
  while((ret = read(fd1, buf, 20)) > 0){
    if(write(fd2, buf, ret) < 0){
      perror("write");
      exit(1);
    }
  }
  */
  //alternatively
  fstat(fd1, &stbuf);
  sendfile(fd2, fd1, 0, stbuf.st_size);

  close(fd1);
  close(fd2);
  system("cat resolv.txt.log");
  return 0;
}
