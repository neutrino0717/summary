#include <stdio.h>
#include <string.h>
//gcc -shared -o libdynamicshared.so libdynamicshared.c
int addnumbers(int a, int b)
{ 
  int sum;
  sum = a + b;
  return sum;
}

