#include <stdio.h>

int main(int argc, char *argv[])
{
  char bits;
  bits = 1;
  printf("before shift: %d\n", bits);

  while(bits != 0){
    bits = bits << 1;  //shift to left 
    printf("after shift to left: %d\n", bits);
  }

  printf("\n");
  bits = 127;
  printf("before shift: %d\n", bits);
  while(bits != 0){
    bits = bits >> 1;  //shift to left 
    printf("after shift to right: %d\n", bits);
  }
  return 0;
}
