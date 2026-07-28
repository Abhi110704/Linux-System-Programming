#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
       printf("Child started (sleep 30)\n");
       execlp("sleep","sleep","30",NULL);
       perror("exeeclp");
       exit(1);
     }
     sleep(5);
     printf("Parent sending SIGKILL...\n");
     kill(pid,SIGKILL);
     wait(NULL);
     printf("Child terminated Forcefully,\n");
     return 0;
}
