#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int ret;
  printf("calling execl..\n");
  ret = execl("uname", "uname", "-a", NULL);
  printf("1. Failed execl... ret = %d\n", ret);

  ret = execl("/bin/uname", "anything I think", "-a", NULL);
  printf("2. Failed execl... ret = %d\n", ret);
  return 0;
}
