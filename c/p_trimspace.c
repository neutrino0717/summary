#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trimstring(char *s){
  char *p = s;
  int len;

  while( *p == ' ' && *p != '\0')
    p++;
  len = strlen(p);
  memmove(s, p, len+1);

  p = s + len - 1;
  while(*p == ' ' && p>s)
    p--;
  //*(p+1) = '\0';  //or
  *(++p) = '\0';
}
int main(int argc, char *argv[])
{
  char str[64] = "      Hello World!       "; //char str[64] = "   Hello World!"; char str[64] = "       "; char str[64] = "";
  printf("str =>%s<=\n", str);

  trimstring(str);
  printf("str =>%s<=\n", str);

  return 0;
}
