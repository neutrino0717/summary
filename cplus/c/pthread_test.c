#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* use:
gcc -o pthread_test.o pthread_test.c -lpthread 
strace ./pthread_test.o  2>pthread_test.c.txt.log
-pthread tells the compiler to link in the pthread library as well as configure the compilation for threads.
*/

void *myfunc (void *myvar);

int main(int argc, char *argv[])
{
  //typedef unsigned long int pthread_t;
  pthread_t thread1, thread2;
  char *arg1 = "first thread";
  char *arg2 = "second thread";
  int ret1, ret2;

  ret1 = pthread_create(&thread1, NULL, myfunc, (void *)arg1);
  ret2 = pthread_create(&thread2, NULL, myfunc, (void *)arg2);

  printf("Main function after pthread_create\n");

  //pread_join() function waits for the thread to terminate
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("First thread return ret1 = %d\n", ret1);
  printf("second thread return ret2 = %d\n", ret2);

  return 0;
}

void *myfunc (void *myvar)
{
  char *msg;
  msg = (char *) myvar;

  int i;
  for (i = 0; i < 10; i++)
  {
    printf("argument: %s %d\n", msg, i);
    sleep(1);
  }
  return NULL;
}
