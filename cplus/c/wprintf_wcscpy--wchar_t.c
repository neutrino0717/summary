#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(int argc, char *argv[])
{
  wchar_t buf[128] = L"Hello World!";
  wchar_t buf2[128];
  wprintf(L"%ls\n", buf);

  wcscpy(buf2, buf);
  wprintf(L"%ls\n", buf2);

  return 0;
}
