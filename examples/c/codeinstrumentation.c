#include <stdio.h>
#include <string.h>

int addnum(int a, int b)
{
  int sum;

#ifdef MYDEBUG
  printf("Debug: entering addnum function %s %d\n", __FILE__, __LINE__);
  printf("Debug: a = %d\n", a);
  printf("Debug: b = %d\n", b);
#endif

  sum = a + b;

#ifdef MYDEBUG
  printf("Debug: leaving addnum function %s %d\n", __FILE__, __LINE__);
  printf("Debug: sum = %d\n", sum);
#endif

  return sum;
}


int main(int argc, char *argv[])
{
  int a, b;
  int sum;

printf("run 'gcc -DMYDEBUG -o %s.o %s' to print debug info\n", __FILE__, __FILE__);

  a = 7;
  b = 17;
  sum = addnum(a, b);
  printf("sum = %d\n", sum);

  return 0;
}
