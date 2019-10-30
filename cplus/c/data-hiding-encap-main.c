#include <stdio.h>
#include "data-hiding-encap-person.h"
/*
gcc -shared -o libperson.so data-hiding-encap-person.c -I. -fpic
gcc -o data-hiding-encap-main.c.o data-hiding-encap-main.c -L. -lperson
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./data-hiding-encap-main.c.o
ldd ./data-hiding-encap-main.c.o
*/
int main(int argc, char *argv[])
{
  pPerson dude = AddName("John", "Doe", 28);
  printf("## DUDE ##\n");

  PrintName(dude);

  return 0;
}

