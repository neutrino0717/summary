#include <stdio.h>
#include <signal.h>

void myhandle(int mysignal){
  printf("--> in myhandle with signal %d\n", mysignal);
}

int main(int argc, char *argv[])
{
  int i = 0;
  signal(SIGINT, myhandle);
  signal(SIGTERM, myhandle);
  signal(SIGKILL, myhandle);//cannot work I think for signal 9

  while(1){
    printf("'ctrl-c' to send signal 2(SIGINT)\n");
    printf("'killall signals.c.o' to send signal 15(SIGTERM)\n");
    printf("'killall -9 signals.c.o' to send signal 9(SIGTERM)\n\n");
    i++;
    sleep(5);
  }
  
  return 0;
}
