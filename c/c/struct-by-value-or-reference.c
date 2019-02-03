#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct add_num_struct_t {
  int a;
  int b;
  int sum;
} add_num_struct;

void get_numbers(int x, int y, add_num_struct mydata) {
  mydata.a = x;
  mydata.b = y;
  mydata.sum = x + y;
}

void get_numbers_ptr(int x, int y, add_num_struct *mydata) {
  mydata->a = x;
  mydata->b = y;
  mydata->sum = x + y;
}

int main(int argc, char *argv[])
{
  add_num_struct newdata;
  get_numbers(2, 5, newdata);
  printf("\n-->wrong:\n");
  printf("newdata.a = %d\n", newdata.a); 
  printf("newdata.b = %d\n", newdata.b); 
  printf("newdata.sum = %d\n", newdata.sum); 

  printf("\n-->right:\n");
  get_numbers_ptr(2, 5, &newdata);
  printf("newdata.a = %d\n", newdata.a); 
  printf("newdata.b = %d\n", newdata.b); 
  printf("newdata.sum = %d\n", newdata.sum); 
  return 0;
}
