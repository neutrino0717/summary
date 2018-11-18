#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

/* use:
gcc -o pthread_mutex.o pthread_mutex.c -lpthread 
strace ./pthread_mutex.o  2>pthread_mutex.c.txt.log

-pthread tells the compiler to link in the pthread library as well as configure the compilation for threads.
*/

void *myfunc1 (void *myvar);
void *myfunc2 (void *myvar);

pthread_mutex_t lock;
int a[100];

int main(int argc, char *argv[])
{
  //typedef unsigned long int pthread_t;
  pthread_t thread1, thread2;
  char *arg1 = "first thread";
  char *arg2 = "second thread";
  int ret1, ret2;

  memset(a, 0, sizeof(a));

  ret1 = pthread_create(&thread1, NULL, myfunc1, (void *)arg1);
  ret2 = pthread_create(&thread2, NULL, myfunc2, (void *)arg2);

  printf("Main function after pthread_create\n");

  //pread_join() function waits for the thread to terminate
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("First thread return ret1 = %d\n", ret1);
  printf("second thread return ret2 = %d\n", ret2);

  return 0;
}

void *myfunc1 (void *myvar)
{
  char *msg;
  msg = (char *) myvar;
  printf("msg: %s\n", msg);

  int i;
  pthread_mutex_lock(&lock);
  for (i = 0; i < 100; i++)
  {
    printf("w%d ",i );
    a[i] = i;
    usleep(10);
  }
  printf("\n");
  pthread_mutex_unlock(&lock);
  return NULL;
}

void *myfunc2 (void *myvar)
{
  char *msg;
  msg = (char *) myvar;
  printf("msg: %s\n", msg);
  sleep(1);

  int i;
  pthread_mutex_lock(&lock);
  for (i = 0; i < 100; i++)
  {
    printf("r%d ", a[i]);
    usleep(10);
  }
  printf("\n");
  pthread_mutex_unlock(&lock);
  return NULL;
}
