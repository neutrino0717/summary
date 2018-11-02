#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int a, b, c;

  for(a = 0; a < 10; a++){
    for(b = 0; b < 10; b++){
      for(c = 0; c < 10; c++){
        if(a == 5 && a == b && b == c)
          goto QUIT_BIG_LOOP;
      }
    }
  } 

  QUIT_BIG_LOOP:

  printf("a = %d, b = %d, c = %d\n", a, b, c);

  return 0;
}
