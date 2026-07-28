#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   pid_t job1,job2;
   job1=fork();
   if (job1==0)
   {
     printf("Job 1 started (sleep 20)\n");
     execlp("sleep","sleep","5",NULL);
     perror("execlp");
     exit(1);
   }
   job2=fork();
   if (job2==0)
   {
     printf("Job 2 started (ls-l)\n");
     execlp("ls","ls","-1",NULL);
     perror("execlp");
     exit(1);
   }
   printf("Supervisor launched both jobs and is exiting immediately.\n");
   return 0;
}
