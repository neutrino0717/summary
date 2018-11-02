#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char buf[11];
  int ret;
/*
  printf("enter some string exceeding length 10:\n");
  //0 is stdin
  ret = read(0, buf, 10);
  //scanf("%s", buf);
  printf("read in %d chars from stdin: %s\n", ret, buf);
*/
  printf("to solve the problem, use a loop, enter a long string:\n");
  while(1)
  {
    ret = read(0, buf, 10);
    if(ret < 10)
    {
      buf[ret] = '\0';
      printf("%s", buf);
      break;
    } else
      buf[ret] = '\0';
      printf("%s", buf);

  }

  return 0;
}
