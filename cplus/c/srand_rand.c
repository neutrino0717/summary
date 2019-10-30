#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  printf("r1 = %d\n", rand());
  printf("r2 = %d\n", rand());
  printf("r3 = %d\n", rand());

  srand((unsigned int) time(NULL));
  printf("after srand r1 = %d\n", rand());
  printf("after srand r2 = %d\n", rand());
  printf("after srand r3 = %d\n", rand());

  printf("after srand, between 1~7 r1 = %d\n", rand() % 6 + 1);
  printf("after srand, between 1~7 r2 = %d\n", rand() % 6 + 1);
  printf("after srand, between 1~7 r3 = %d\n", rand() % 6 + 1);
  return 0;
}
