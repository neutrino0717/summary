#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a;
  a = 10;
  switch (a) {
    case 0:
      printf("case is 0\n");
      break;
    case 1:
      printf("case is 1\n");
      break;
    case 2:
      printf("case is 2\n");
      break;
    default:
      printf("case is default\n");
      break;
  }
  return 0;
}
