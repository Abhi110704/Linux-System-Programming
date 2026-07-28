#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
   {
       printf("Child started (sleep 30)\n");
       execlp("sleep","sleep","30",NULL);
       perror("execlp");
       exit(1);
   }
   sleep(5);
   printf("Parent sending SIGTERM...\n");
   kill(pid,SIGTERM);
   wait(NULL);
   printf("Child terminated gracefully.\n");
   return 0;
}
