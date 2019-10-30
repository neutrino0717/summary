#include <stdio.h>
#define NUM1 7
#define NUM2 11 


int main(int argc, char *argv[])
{
  int i,j;
  int sum;
  i = NUM1;
  j = NUM2;

  sum = i + j;

  printf("run 'gcc -E -c preprocessor.c'\n");
  return 0;
}
