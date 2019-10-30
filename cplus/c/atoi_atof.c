#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *strint = "5782";
  char *strdb1 = "5927.4578";

  int a;
  double b;
  a = atoi(strint);
  b = atof(strdb1);

  printf("a = %d\n", a);
  printf("b = %f\n", b);

  return 0;
}
