#include <stdio.h>

int addn(int a, int b)
{
  return a + b;
}

int main(int argc, char *argv[])
{
  int (*addn_ptr)(int,int);
  addn_ptr = &addn; 
  printf("result: %d\n", addn(7,11));
  printf("result: %d\n", addn_ptr(7,11));
}
