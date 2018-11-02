#include <stdio.h>
int main(int argc, char *argv[]){
  char name[128];
  char city[128];
  char state[64];
  int age;
  printf("run: cat scanf--scanfset.conf | /tmp/scanf--scanfset.c.o\n");
  while(scanf("%127[^,],%d,%127[^,],%63[^\n]\n", name, &age, city, state) == 4){
    printf("%-5s %-15s %-20s %4d\n", state, city, name, age);
  }
  return 0;
}
