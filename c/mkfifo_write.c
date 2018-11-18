#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd, retval;
  char buffer[8] = "TESTDATA";
  fflush(stdin);
  //create the named pipe, with permissions 0666
  retval = mkfifo("/tmp/myfifo", 0666);
  //open the fifo
  fd = open("/tmp/myfifo", O_WRONLY);
  //writing into the fifo, fd is for idenfitication of the pipe
  write(fd, buffer, sizeof(buffer));
  close(fd);
  return 0;

}
