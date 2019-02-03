#include <stdio.h>
int addnumbers(int a, int b);
/*
for dynamic
  gcc -shared -o libdynamicshared.so libdynamicshared.c
  gcc -o libdynamicshared_test.o libdynamicshared_test.c -L. -ldynamicshared
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
  ./libdynamicshared_test.o
  ldd ./libdynamicshared_test.o
for static
   gcc -c libstaticshared.c
   ar -cvq libstaticshared.a libstaticshared.o
   nm libstaticshared.o
   nm libstaticshared.a
   nm -s libstaticshared.a
   ranlib libstaticshared.a
   nm -s libstaticshared.a
   gcc -o libstaticshared_test.o libstaticshared_test.c libstaticshared.a
   ./libstaticshared_test.o
   ldd libstaticshared_test.o
   nm libstaticshared_test.o
*/
int main(int argc, char *argv[])
{
  int total;
  total = addnumbers(7, 17);
  printf("total = %d\n", total);

  return 0;
}
