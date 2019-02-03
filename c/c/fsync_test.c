#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char *str = "this is a string to go to the file.\n";
  int fd;
  int ret;

  fd = creat("/tmp/hello.txt", S_IWUSR | S_IRUSR);
  if(fd < -1){
    perror("creat()");
    exit(1);
  }

  ret = write(fd, str, strlen(str));
  if(ret < -1) {
    perror("write()");
    exit(1);
  }
  system("cat /tmp/hello.txt");

  fsync(fd);
  system("cat /tmp/hello.txt");
  /*
    very long lines of code blah blah blah
  */
  close(fd);

  return 0;
}
