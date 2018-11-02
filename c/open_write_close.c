#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  int fd;
  char buf[14];

  fd = open("myfile.txt.log", O_CREAT | O_WRONLY, 0600);
  if(fd == -1)
  {
    printf("Failed to create and open the file.\n");
    exit(1);
  }
  write(fd, "Hello World!\n", 13);
  close(fd);

  /* read */
  fd = open("myfile.txt.log", O_CREAT| O_RDONLY, 0600);
  if(fd == -1)
  {
    printf("Failed to open and read the file.\n");
    exit(1);
  }
  read(fd, buf, 13);
  buf[13] = '\0';
  close(fd);
  printf("buf: %s\n", buf); 

  return 0;
}
