#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define	MAXLINE	4096			/* max line length */
int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% "); //print prompt%

    while(fgets(buf,MAXLINE,stdin)!=NULL)
    {
        if(buf[strlen(buf)-1]=='\n')
            buf[strlen(buf)-1] = 0; //replace newline with NULL
        if(pid=fork()<0)
        {
            printf("fork error");
        }
        else if (pid==0)
        {
            execlp(buf,buf,(char*)0);
            printf("couldn't execute: %s",buf);
            exit(127);
        }

        // parent
        if((pid=waitpid(pid,&status,0))<0)
            printf("waitpid error");
        printf("%% ");
    }
    
    return 0;
}