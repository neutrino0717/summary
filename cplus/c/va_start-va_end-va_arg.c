#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int sumnum(int num, ...){
  int sum = 0;
  va_list argptr; 
  int count = 0;

  va_start(argptr, num);
  while(count < num){
    sum += va_arg(argptr, int);
    count++;
  }
  va_end(argptr);

  return sum;
}

void printstr(int num, ...){
  int count = 0;
  char *ptr;
  va_list argptr;
  char sum[200];

  va_start(argptr, num);
  while(count < num){
    ptr = va_arg(argptr, char*);
    //printf("ptr = %s\n", ptr);
    strcat(sum, ptr);
    count++;
  }
  va_end(argptr);
  printf("the string concatenation is: %s\n", sum);
}

int main(int argc, char *argv[])
{
  int total;
  total = sumnum(5, 1, 2, 3, 4, 5);
  printf("the sum of 1~5 is: %d\n", total);
  printstr(3, "one ", "two ", "three ");

  return 0;
}
