#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  union {
    int a;
    int b;
    char s[8];
  } myunion;
  strcpy(myunion.s, "happy");

  printf("note for ascii code: 68->h, 61->a, 70->p, 70->p\n");
  printf("a = %d\n", myunion.a);
  printf("a = %x\n", myunion.a);
  printf("b = %d\n", myunion.b);
  printf("b = %x\n", myunion.b);
  printf("s = %s\n", myunion.s);
  myunion.a = 3;
  return 0;
  
}
