#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gdbm.h>

typedef struct myd_tag {
  char first[24];
  char last[24];
} myd;
/*
man gdbm
info gdbm
compile with "gcc -o gdbm_test.c.o gdbm_test.c -lgdbm"
or "gstrace gdbm_test.c -lgdbm"
*/
int main(int argc, char *argv[])
{
  GDBM_FILE file;
  datum key1, data1, ndata1;
  datum key2, data2, ndata2;

  char *k1 = "msg1";
  char *d1 = "I love c programming.";
  char *k2 = "msg2";
  myd   d2 = {"John", "Doe" };

  key1.dptr   = k1;
  key1.dsize  = strlen(k1) + 1;
  data1.dptr  = d1;
  data1.dsize = strlen(d1) + 1;

  key2.dptr   = k2;
  key2.dsize  = strlen(k2) + 1;
  data2.dptr  = (char *)&d2;
  data2.dsize = sizeof(d2);

  system("rm -rf /tmp/mydb");

  file = gdbm_open("/tmp/mydb", 0, GDBM_WRCREAT | GDBM_READER, 0660, 0);
  gdbm_store(file, key1, data1, GDBM_INSERT);
  gdbm_store(file, key2, data2, GDBM_INSERT);

  ndata1 = gdbm_fetch(file, key1);
  ndata2 = gdbm_fetch(file, key2);

  printf("ndata1: %s\n", ndata1.dptr);
  printf("ndata2: %s\n", ((myd *)ndata2.dptr)->first);
  printf("ndata2: %s\n", ((myd *)ndata2.dptr)->last);
  gdbm_close(file);

  return 0;
}
