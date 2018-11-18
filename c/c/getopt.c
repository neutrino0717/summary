#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int c;
  int xflg = 0, yflg = 0, zflg = 0;
  char *xoptarg;
  if(argc == 1){
  printf("run the following commands:\n"
"/tmp/%s.o\n"
"/tmp/%s.o -a\n"
"/tmp/%s.o -x\n"
"/tmp/%s.o -yz -x 3\n"
"/tmp/%s.o -xyzp\n\n", __FILE__, __FILE__, __FILE__, __FILE__, __FILE__);
}
  while( (c = getopt(argc, argv, "x:yz")) != -1 ) {
    switch(c) {
      case 'x':
        xflg = 1;
        xoptarg = optarg;
        break;
      case 'y':
        yflg = 1;
        break;
      case 'z':
        zflg = 1;
        break;
      case '?':
        fprintf(stderr, "error with option -%c. \n", optopt);
        break;
      default:
        fprintf(stderr, "getopt");
    }

  }
  printf("options and arguments:\n");
  printf("xflg = %d, xoptarg=%s\n", xflg, xoptarg);
  printf("yflg = %d\n", yflg);
  printf("zflg = %d\n", zflg);
  return 0;
}
