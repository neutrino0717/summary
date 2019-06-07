#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insert_binary(char *str, char d){
  int len = strlen(str);
  memmove(&str[1], str, len + 1);
  str[0] = d;
}
int main(int argc, char *argv[])
{
  int i;
  char binary[1024]  = "";
  //printf("this is %s\n", binary);
  int n, r;
  if(argc < 2){
    fprintf(stderr, "Usage: %s number\n", argv[0]);
    exit(0);
  }
  i = atoi(argv[1]);
  do
  {
    n = i/2;
    r = i%2;
    /* insert digit remainder to the leftmost */
    insert_binary(binary, r?'1':'0');
    i = n;

  }while(i);

  printf("binary = %s\n", binary);
  return 0;
}
//gcc -o digital2binary.c.o digital2binary.c && digital2binary.c.o
