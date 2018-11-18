#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  char *day[7] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
  };

  printf("run below:\n");
  printf("-->gcc -g -o gdbdebugger1.c.o gdbdebugger1.c\n");
  printf("-->gdb gdbdebugger1.c.o\n");
  printf("---->run\n");
  printf("---->list\n");
  printf("---->where\n");
  printf("---->up\n");
  printf("---->up\n");
  printf("---->print i\n");
  printf("---->print day[i]\n");
  printf("---->print day[6]\n");
  printf("---->down\n");
/*
(gdb) print day[i]
$2 = 0x100000000 <error: Cannot access memory at address 0x100000000>
(gdb) print day[6]
$3 = 0x40070a "Sunday"
*/

  //for(i = 0; i < 7; i++){
  for(i = 0; i < 14; i++){
    printf("day[%d] = %s\n", i, day[i]);
  }
  return 0;
}
