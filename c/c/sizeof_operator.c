#include <inttypes.h>
#include <stdio.h>
#include <string.h>
int main() {
  printf( "    short int: %zd\n" , sizeof(short int) ) ;
  printf( "          int: %zd\n" , sizeof(int) ) ;
  printf( "        float: %zd\n", sizeof(float) ) ;
  printf( "       double: %zd\n", sizeof(double) ) ;
  printf( "     long int: %zd\n", sizeof(long int) ) ;
  printf( "long long int: %zd\n", sizeof(long long int) ) ;
  printf( "       size_t: %zd\n", sizeof(size_t) ) ;
  printf( "        void*: %zd\n\n", sizeof(void *) ) ;

  char str1[100] = "hello world";
  printf( "         str1: %s\n", str1) ;
  printf( "      str1[6]: %c\n", str1[6]) ;
  printf( "  sizeof str1: %zd\n", sizeof(str1) ) ;
  printf( "  strlen str1: %zd\n", strlen(str1) ) ;
  return 0; 

}
