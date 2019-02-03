#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int fd;
  int ret;
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int b = 11;
  char *fname = "/tmp/outfile";
  fd = open("/tmp/outfile", O_CREAT | O_APPEND | O_RDWR, 0600);
  /* write something */
  ret = write(fd, (void *)a, sizeof(a)); 
  /* seek using lseek */
  ret = lseek(fd, 3*sizeof(int), SEEK_SET);
  /* read from that postion set by lseek */
  ret = read(fd, &b, sizeof(int));
  printf("after lseek 3 int, b = %d\n", b);
  ret = lseek(fd, 6*sizeof(int), SEEK_SET);
  ret = read(fd, &b, sizeof(int));
  printf("after lseek 6 int, b = %d\n", b);
  //ret = write(fd, &b, sizeof(int)); 

  close(fd);

  return 0;
}
