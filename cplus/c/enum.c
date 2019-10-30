#include <stdio.h>
#include <string.h>

/*or
typedef enum myday {
...
} mymyday;

mymyday aday;

*/
enum myday {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  xxx = 2,
  yyy,
  zzz,
};

int main(int argc, char *argv[])
{
  enum myday aday;

  printf("Sunday = %d\n", Sunday);
  printf("Monday = %d\n", Monday);
  printf("Saturday = %d\n", Saturday);
  printf("xxx = %d\n", xxx);
  printf("yyy = %d\n", yyy);
  printf("zzz = %d\n", zzz);
  printf("\n");

  aday = xxx;
  printf("aday = %d\n", aday);

  return 0;
}
