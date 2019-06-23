#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myfunction(){
  printf("This is a line number %d\n", __LINE__);
  printf("This is file %s\n", __FILE__);
  printf("This is function %s\n", __func__);

}

int main(int argc, char *argv[])
{
  myfunction();
  return 0;
}
