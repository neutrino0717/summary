#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100
int main(int argc, char *argv[])
{
  int shmid;
  key_t key;
  char *shm;
  char *s;

  key = 9876;
  shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);
  if(shmid < 0) {
    perror("shmget");
    exit(1);
  }
  printf("shmid: %d\n", shmid);
  shm = shmat(shmid, NULL, 0);
  if(shm == (char *) -1) {
    perror("shmat");
    exit(1);
  }
  printf("shm: %s\n", shm); 
  printf("shm address: %p\n", (void *)shm); 
  printf("run 'ipcs -m' to check the shared memory created\n");
  printf("run 'ipcrm -M 9876' to remove the shared memory\n");
  memcpy(shm, "Hello World", 11);
  s = shm;
  s += 11;
  *s = 0;

  while(*shm != '*')
    sleep(1);
  
  return 0;
}
