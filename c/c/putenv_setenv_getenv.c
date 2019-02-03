#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *p;
  p = getenv("SHELL");
  printf("SHELL is %s\n", p);
  p = getenv("MYENV");
  printf("MYENV is %s\n", p);

  putenv("MYENV=hello");
  perror("putenv");

  setenv("MYENV2", "welcome", 0);
  perror("setenv");

  printf("MYENV is %s\n", getenv("MYENV"));
  printf("MYENV2 is %s\n", getenv("MYENV2"));
  
  return 0;
}
