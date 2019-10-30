#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a;
  a = 2;

  {
    int a;
    a = 4;  //inside curly braces scope
    printf("inside curly braces:  a = %d\n", a);

  }

  printf("outside curly braces: a = %d\n", a);
  return 0;
}
