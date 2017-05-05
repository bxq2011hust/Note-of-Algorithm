#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char ** argv)
{
    DIR *dp;
    struct dirent *dirp;
    char defaultPath[]=".";
    if (argc!=2)
    {
        printf("current directory.\n");
        if((dp=opendir(defaultPath))==NULL)
            printf("can't open %s\n",defaultPath);
    }
    else
    {
        if((dp=opendir(argv[1]))==NULL)
            printf("can't open %s\n",defaultPath);
    }
    while((dirp=readdir(dp))!=NULL)
        printf("%s\n",dirp->d_name);
    closedir(dp);
    return 0;
}
