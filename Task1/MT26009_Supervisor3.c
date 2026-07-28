#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main()
{
     signal(SIGCHLD,SIG_IGN);
     if (fork()==0)
     {
        printf("Job1 is started (sleep 5)\n");
        execlp("sleep","sleep","5",NULL);
        perror("execlp");
        exit(1);
     }
     if (fork()==0)
     {
        printf("Job 2 started (ls -l)\n");
        execlp("ls","ls","-l",NULL);
        perror("execlp");
        exit(1);
     }
     printf("Supervisor is running but will not collect child exit status.\n");
     sleep(8);
     printf("Supervisor exiting.\n");
     return 0;
}
