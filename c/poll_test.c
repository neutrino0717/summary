#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>

int main(int argc, char *argv[])
{
  int fd;
  char buf[100];
  int ret, pret;

  fd = 0;  //read from termial

  struct pollfd fds[1];
  int timeout;


  while(1){
    fds[0].fd = fd;
    fds[0].events = 0;
    fds[0].events |= POLLIN;

    timeout = 5000;

    pret = poll(fds, 1, timeout);
    if(pret == 0){
      printf("pret = %d\n", pret);
      printf("   timeout\n");
    } else {
      memset((void *) buf, '\0', 11); //copy 11 end of string to buf,
      ret = read(fd, (void *) buf, 10);
      printf("ret = %d\n", ret);
      
      if(ret != -1){
        printf(" buf = %s\n", buf);
      }
    }
  }

  return 0;
}
