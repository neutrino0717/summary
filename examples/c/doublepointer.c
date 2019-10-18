#include <stdio.h>
#include <string.h>

void swapptr(int **a, int **b){
  int *tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//will not work, for the change is only for local
void swapptr2(int *a, int *b){
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}


void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}


int main(int argc, char *argv[])
{
  int x, y;
  int *m, *n;
  int *tmp;

  x = 7;
  y = 17;

  m = &x;
  n = &y; 

printf("*m = %d\n", *m);
  printf("*n = %d\n", *n);
  printf("m = %p\n", m);
  printf("n = %p\n", n);
  printf("x = %d\n", x);
  printf("y = %d\n", y);

  printf("\nSwapping pointer!, x,y changed\n");
  swapptr(&m, &n);
  printf("*m = %d\n", *m);
  printf("*n = %d\n", *n);
  printf("m = %p\n", m);
  printf("n = %p\n", n);
  printf("x = %d\n", x);
  printf("y = %d\n", y);
  
  printf("\nSwapping value\n");
  swap(m, n);
  printf("*m = %d\n", *m);
  printf("*n = %d\n", *n);
  printf("m = %p\n", m);
  printf("n = %p\n", n);
  printf("x = %d\n", x);
  printf("y = %d\n", y);
  return 0;
}
