#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a[3][3] = { {11, 12, 13},
                  {21, 22, 23},
                  {31, 32, 33} };
  int i, j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      printf("a[%d][%d] = %d\n", i, j, a[i][j]);
    }
  }

  return 0;
}
//gcc -o 2dimensinalarray.c.o 2dimensinalarray.c && 2dimensinalarray.c.o
