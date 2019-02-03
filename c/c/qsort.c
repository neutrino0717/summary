#include <stdio.h>
#include <stdlib.h>

int comparefunc(const void *a, const void *b)
{
  int aa, bb;
  aa = *(int *)a;
  bb = *(int *)b;
  return (aa - bb);
  
}
int main(int argc, char *argv[])
{
  int numbers[] = { 5, 2, 20, 7, 9, 1, 44, 17, 22, 7 };
  printf("Before sort\n");
  int i;
  for ( i = 0; i< 10; i++)
    printf("%d ", numbers[i]);
  printf("\n\n");

  qsort(numbers, 10, sizeof(int), comparefunc);

  printf("After sort\n");
  for (i = 0; i< 10; i++)
    printf("%d ", numbers[i]);
  printf("\n\n");

  return 0;
}
