#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
  char buf[32];
  struct tm *mytm;
  time_t mytime;
  mytime = time(NULL);
  mytm = localtime(&mytime);
  
  /* 2016-01-03 22:40:00 */
  strftime(buf, 31, "%Y-%m-%d %I:%M:%S %p", mytm);
  printf("Date and Time: %s\n", buf); 
  strftime(buf, 31, "%Y-%m-%d %H:%M:%S", mytm);
  printf("Date and Time: %s\n", buf); 
  return 0;

}
