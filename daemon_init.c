/*name : daemon_init.c
 function: 创建一个守护进程
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

void daemon_init()
{
    int pid;
    int i;

    if(signal(SIGCHLD,SIG_IGN)==SIG_ERR)
    {
        printf("can't singal daemon_init;\n");
	exit(1);
    }

    if(pid=fork())
       exit(0);
    else if(pid<0){
       perror("fail to fork\n");
       exit(1);
       }

    if(setsid()<0)
    {
        exit(0);
    }

    if(pid=fork())
        exit(0);
    else if(pid<0)
        exit(1);

    for(i=0; i<getdtablesize(); i++)
       close(i);
    chdir("/");
    umask(0);
    return;
}

