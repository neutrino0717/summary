#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd, retval;
  char buffer[8];
  //open the fifo
  fd = open("/tmp/myfifo", O_RDONLY);
  //read the fifo, and put the content into the buffer
  retval = read(fd, buffer, sizeof(buffer));
  //fflush(stdin);
  write(1, buffer, sizeof(buffer));
  close(fd);
  return 0;

}
