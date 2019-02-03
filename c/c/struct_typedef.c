#include <stdio.h>

typedef int INT32;
typedef char MYCHR;

int main(int argc, char *argv[])
{
  struct{
    int a;
    float b;
    int c;
  } myst1;

  typedef struct mystr_t {
    int a;
    float b;
    int c;
  } MYSTRX;

  myst1.a = 7;
  myst1.b = 11.9;
  myst1.c = 8;
  
  MYSTRX myst2;
  myst2.a = 7;
  myst2.b = 11.9;
  myst2.c = 8;


  printf ("a = %d, b = %f, c = %d\n", myst1.a, myst1.b, myst1.c);
  printf ("a = %d, b = %f, c = %d\n", myst2.a, myst2.b, myst2.c);

  INT32 i = 7;
  MYCHR mystr[20] = "hello, world";
  printf("mystr = %s, i = %d\n", mystr, i);

  return 0;
}

