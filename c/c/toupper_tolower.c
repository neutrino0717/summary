#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char mystr[] = "Hello World!";
  char *p;
  int i;

  p = mystr;

  printf("%s\n", mystr);
  while(*p != '\0'){
    *p = (char) toupper(*p);
    p++;
  }
  printf("%s\n", mystr);

  i = 0;
  while(mystr[i] != '\0'){
    mystr[i] = tolower(mystr[i]);
    i++;
  }
  printf("%s\n", mystr);
  return 0;
}
