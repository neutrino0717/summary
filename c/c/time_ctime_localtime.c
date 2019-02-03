#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
  time_t mytime;
  struct tm *mytm;

  mytime = time(NULL);
  printf("%s\n", ctime(&mytime));

  mytm = localtime(&mytime);
  printf("Year: %d\n", 1900 + mytm->tm_year);
  printf("Month: %d\n", 1 + mytm->tm_mon);
  printf("Day of oth: %d\n", mytm->tm_mday);
  printf("DST: %d\n", mytm->tm_isdst);

  return 0;
}
