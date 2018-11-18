#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fs;
  char buf[10];
  size_t sz;

  fs = fopen("/etc/hosts", "r");
  if(fs == NULL){
    perror("fopen");
    exit(1);
  }
  while(!feof(fs)) {
    sz = fread((void *)buf, 1, 9, fs);
    //sz--> the number of elements read actually 
    //1 --> the size of each element
    //9 --> the number of elements to read
    //buf[9] = '\0';
    buf[sz*1] = '\0';
    printf("%s",buf);
  }
  //printf("\n");
  fclose(fs);

  return 0;
}
