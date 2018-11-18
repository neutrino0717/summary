#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "color.h"

int main(int argc, char *argv[])
{

  int ret;
  char *cmd = "ls -al mynewdir hellodir";
  //dr-xr-xr--
  ret = mkdir("mynewdir",S_IRUSR|S_IRGRP|S_IROTH|S_IXUSR|S_IXGRP);
  ret  = symlink("mynewdir", "hellodir");
 
  printf("%s%s%s\n", KRED, cmd, KRST);
  system(cmd);

  ret = rmdir("mynewdir");
  ret = unlink("hellodir");
  system(cmd);

  printf("%s%s%s\n", KRED, cmd, KRST);
  return 0;
}
