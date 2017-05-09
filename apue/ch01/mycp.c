#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 4096

int main(int argc , char * argv[])
{
    // no cache io
    // int n;
    // char buf[BUFFSIZE];

    // while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0)
    //     if(write(STDOUT_FILENO,buf,n)!=n)
    //         printf("write error.\n");
    
    // if(n<0)
    //     printf("read error.");

    // std io
    int c;
    while((c=getc(stdin))!=EOF)
        if(putc(c,stdout)==EOF)
            printf("uotput error\n");

    if(ferror(stdin))
        printf("input error");
        
    return 0;
}
