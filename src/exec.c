#include "../include/apue.h"
#include <sys/wait.h>

int main(void)
{
    int status;
    char buf[MAXLINE];
    pid_t pid;

    printf("%% ");
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if((pid = fork()) < 0){
            printf("error");
        }else if(pid == 0){ /* child process */
            execlp(buf, buf, (char *)0);
            printf("couldn't execute: %s", buf);
            exit(127);
        }
        /* parent process */
        if(pid = waitpid(buf, &status, 0) < 0)
            printf("error");
        printf("%% ");
    }
    exit(0);
}
