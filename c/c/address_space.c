#include <inttypes.h>
#include <stdio.h>
#include <string.h>
int main() {
/*
man 3 printf
       p      The void * pointer argument is printed in hexadecimal (as if by %#x or %#lx).
*/
  char str1[100] = "hello world";
  int i = 7;
  int *j = &i;
  printf( "         str1 address: %p\n", (void *)&str1) ;
  printf( "      str1[6] address: %p\n", (void *)&str1[6]) ;
  printf( "        int i address: %p\n", (void *)&i ) ;
  printf( "        int*j content: %p\n", j ) ;
  printf( "       int* j address: %p\n", (void *)&j ) ;
  return 0; 

}

//gcc -o address_space.c.o address_space.c && address_space.c.o
