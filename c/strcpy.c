#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char buf[11];
  strcpy(buf, "helloworld");
  printf("%s\n", buf);
  return 0;
}
