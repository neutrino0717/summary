#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int childpid;
  int count1 = 0, count2 = 0;

  printf("-->Before it forks\n");
  childpid = fork();

  if(childpid ==0)  //this is child
  {
    printf("This is a child process: %d\n", childpid);
    while(count1 < 10)
    {
      printf("child process: %d\n", count1);
      sleep(1);
      count1++;
    } 

  } else {
    printf("This is a parent process: %d\n", childpid);
    while(count2 < 10)
    {
      printf("parent process: %d\n", count2);
      sleep(1);
      count2++;
    } 


  } 
  return 0;
}
