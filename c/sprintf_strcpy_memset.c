#include <stdio.h>
#include <string.h>
//man 3 string
int main(int argc, char *argv[])
{
  char str[13];
  int i;
/*sprintf*/ 
  sprintf(str, "hello, world"); // in string.h
  printf("sprintf str=%s\n", str);
  printf("  the length of str is %zu\n", strlen(str)); //z: A following integer conversion corresponds to a size_t or ssize_t argument.
  printf("  the sizeof char array is %zu\n\n", sizeof(str));
/*strcpy*/
  //sprintf vs. strcpy
  char str2[24];
  strcpy(str2, str);
  printf("strcpy str=%s\n\n", str2);
/* memset*/
  memset(str, 0, 13);
  printf("memset >%s<\n", str);
  memset(str, 'a', 3);
  printf("memset >%s<\n", str);
  memset(str, 'b', 12);
  printf("memset >%s<\n", str);
  return 0;
}
