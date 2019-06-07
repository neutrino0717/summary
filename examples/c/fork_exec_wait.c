/****************************************************************
 *
 *    Example: to demonstrate fork() and execl() and system calls
 *
 ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main( int argc, char *argv[], char *env[] )
{
   pid_t my_pid, parent_pid, child_pid;
   int status;

   my_pid = getpid();    
   parent_pid = getppid();
   printf("before fork: pid is %d, ppid is %d", my_pid, parent_pid);

   if((child_pid = fork()) < 0 )
   {
      perror("fork failure");
      exit(1);
   }

/* fork() == 0 for child process */

   if(child_pid == 0)
   {  printf("5.Child: I am a new-born process!\n\n");
      my_pid = getpid();    parent_pid = getppid();
      printf("6.Child: my pid is: %d\n\n", my_pid);
      printf("7.Child: my parent's pid is: %d\n\n", parent_pid);
      printf("8.Child: I will sleep 3 seconds and then execute - date - command \n\n");

      sleep(3); 
      printf("9.Child: Now, I woke up and am executing date command \n\n");
      execl("/bin/date", "date", 0, 0);
      perror("execl() failure!\n\n");

      printf("This print is after execl() and should not have been executed if execl were successful! \n\n");

      _exit(1);
   }
/*
 * parent process
 */
   else
   {
      printf("3.Parent: I created a child process.\n\n");
      printf("4.Parent: my child's pid is: %d\n\n", child_pid);
      system("ps auxwwf |sed -n '1p;/fork/p'");  printf("\n \n");
      wait(&status); /* can use wait(NULL) since exit status
                        from child is not used. */
      printf("10.Parent: my child process is dead. I am going to leave.\n \n ");
   }

   return 0;
}
