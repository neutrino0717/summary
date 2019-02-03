#include <stdio.h>
#include <string.h>

int addnum(int a, int b)
{
  int sum;
  sum = a + b;
  return sum;
}


int main(int argc, char *argv[])
{
  int a, b;
  int sum;

  a = 7;
  b = 17;
  sum = addnum(a, b);
  printf("sum = %d\n", sum);

  printf(
"--> gcc -g -o gdbdebugger2.c.o gdbdebugger2.c\n"
"--> gdb gdbdebugger2.c.o\n"
"----> b 17\n"
"----> run\n"
"----> list\n"
"----> print a\n"
"----> next\n"
"----> step\n"
"----> print a\n"
"----> next\n"
"----> print sum\n"
"----> continue\n"
);
  return 0;
}
