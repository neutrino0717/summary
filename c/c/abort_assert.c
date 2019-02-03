#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i;
  printf("compile: gcc -g -o abort_assert.c.o abort_assert.c\n");
  printf("run:\n"
            "  ./abort_assert.c.o assert|abort\n" "debug:\n  gdb ./abort_assert.c.o\n"
            "    run\n"
            "    list\n"
            "    where\n");
  printf("begin...\n");
  printf("%s\n", argv[1]);
  if(!strcmp(argv[1], "abort")){
    abort();
  }else {
    for(i = 0; i<10; i++){
      printf("i = %d\n", i);
      assert(i <= 5);
    }
  }

  printf("end...\n");
  return 0;
}

//gcc -g -o abort_assert.c.o abort_assert.c && abort_assert.c.o assert 
