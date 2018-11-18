#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char str[24] = "hello, world";
  char *ptr    = str;
  char *ptr1   = "hello, world";
  printf("str = %s\n", str);
  printf("ptr = %s\n", ptr);
  printf("str: %p\n", (void*)&str);
  printf("ptr: %p\n", (void*)&ptr);
  printf("ptr1: %p\n", (void*)&ptr1);
  return 0;
}
