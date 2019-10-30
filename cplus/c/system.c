#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int ret;
  ret = system("id -a"); 
  printf("the return value: ret=%d\n", ret);

  return 0;
}
