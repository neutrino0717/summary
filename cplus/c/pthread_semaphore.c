#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* use:
gcc -o pthread_semaphore.o pthread_semaphore.c -lpthread 
strace ./pthread_semaphore.o  2>pthread_semaphore.c.txt.log
-pthread tells the compiler to link in the pthread library as well as configure the compilation for threads.
*/

void *myfunc1 (void *myvar);
void *myfunc2 (void *myvar);

char buf[24];
sem_t mutex;

int main(int argc, char *argv[])
{
  //typedef unsigned long int pthread_t;
  pthread_t thread1, thread2;
  char *arg1 = "first thread";
  char *arg2 = "second thread";
  sem_init(&mutex, 0, 1);
  int ret1, ret2;

  ret1 = pthread_create(&thread1, NULL, myfunc1, (void *)arg1);
  ret2 = pthread_create(&thread2, NULL, myfunc2, (void *)arg2);

  printf("Main function after pthread_create\n");

  //pread_join() function waits for the thread to terminate
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  printf("First thread return ret1 = %d\n", ret1);
  printf("second thread return ret2 = %d\n", ret2);
  
  sem_destroy(&mutex);
  return 0;
}

void *myfunc1 (void *myvar)
{
  char *msg;
  msg = (char *) myvar;
  printf("msg: %s\n", msg);

  sem_wait(&mutex);
  sprintf(buf, "%s", "Hello There!");
  sem_post(&mutex);

  pthread_exit(0);
}

void *myfunc2 (void *myvar)
{
  char *msg;
  msg = (char *) myvar;
  printf("msg: %s\n", msg);

  sem_wait(&mutex);
  printf("buf: %s\n", buf);
  sem_post(&mutex);

  pthread_exit(0);
}
