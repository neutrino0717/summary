#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{

  char str1[]  = "hello";
  printf("%s\n", str1);
  printf("strlen: %zu, sizeof: %zu\n", strlen(str1), sizeof(str1));
}
