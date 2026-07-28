#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   pid_t job1,job2;
   int status;
   job1 = fork();
   if (job1==0)
   {
      printf("Job 1 started (sleep 20)\n");
      execlp("sleep","sleep","20",NULL);
      perror("execlp");
      exit(1);
   }
   job2 = fork();
   if (job2==0)
   {
      printf("Job 2 started (ls-l)\n");
      execlp("ls","ls","-1",NULL);
      perror("execlp");
      exit(1);
   }   
   printf("Supervisor is waiting for both jobs...\n");
   waitpid(job1,&status,0);
   printf("Job 1 finished.\n");
   waitpid(job2,&status,0);
   printf("Job 2 finished.\n");
   printf("\nExecution Summary\n");
   printf("--------------\n");
   printf("Job 1 : Completed\n");
   printf("Job 2 : Completed\n");
   return 0;
}
