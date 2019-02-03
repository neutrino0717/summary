#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
  struct stat buf;
  char mtime[100];

  stat("/etc/hosts", &buf);
  //converts a unsigned integer into octal representation oooo
  strcpy(mtime, ctime(&buf.st_mtime));
  printf("st_mode = %o\n", buf.st_mode);
  printf("st_mtime = %s\n", mtime);
  printf("note: 100000 is regular file\n"
         "         644 is the file mode bits\n");
  return 0;
}
