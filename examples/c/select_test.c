#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
  int fd;
  char buf[100];
  int ret, sret;

  fd = 0;  //read from termial
  fd_set readfds;
  struct timeval timeout;


  while(1){
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    sret = select(8, &readfds, NULL, NULL, &timeout);
    if(sret == 0){
      printf("sret = %d\n", sret);
      printf("   timeout\n");
    } else {
      memset((void *) buf, '\0', 11); //copy 11 end of string to buf,
      ret = read(fd, (void *) buf, 10);
      printf("ret = %d\n", ret);
      
      if(ret != -1){
        //buf[10] = '\0';
        printf(" buf = %s\n", buf);
      }
    }
  }

  return 0;
}
