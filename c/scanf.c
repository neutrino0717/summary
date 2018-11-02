#include <stdio.h>

int main(int argc, char *argv[])
{
  int input;
  printf("enter a integer:\n");
  scanf("%d", &input);
  printf("input = %d\n", input);

  char name[10];
  printf("enter a string\n");
  scanf("%s", name);
  printf("name = %s\n", name);

  return 0;
}
