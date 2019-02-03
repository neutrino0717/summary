#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

int breakfields(char *s, char **data, int n){
  int fields = 0;
  int i;
  char *start = s;
  char *end = s;
  bool isend = false;

  for(i = 0; i < n; i++){
    while( *end != ',' && *end != '\0'){
      end++;
    }    

    if(*end == ','){
      *end = '\0';
    }

    data[i] = (char *)malloc(strlen(start)+1);
    strcpy(data[i], start);
    fields++;
    
    if(! isend){
      start = end + 1;
      end = start;
    }

    if(isend){
      break;
    }
  }

  return fields;
}

int main(int argc, char *argv[])
{
  char str[128] = "Steve,28 Palm St,Honolulu,HI,98765";
  int i;
  char *data[5];
  int ret;
  printf("str = %s\n", str);

  ret = breakfields(str, data, 5);
  for(i = 0; i < 5; i++){
    printf("data[%d] = %s\n", i, data[i]);
    //free(data[i]);
  }

  printf("Number of fields processed = %d\n", ret);
  return 0;
}
