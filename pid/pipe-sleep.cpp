#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
int main(void){
    int fds[2];

    if( pipe(fds) == -1){
        perror("pipe error");
        exit(EXIT_SUCCESS);
    }

    pid_t pid;
    pid =fork();
    if(pid == -1){
        perror("fork error");
        exit(EXIT_SUCCESS);
    }

    if(pid == 0){
        close(fds[0]);//子进程关闭读端；
        sleep(10);//睡眠10秒；
        write(fds[1],"hello",5);
        exit(EXIT_SUCCESS);
    }

    close(fds[1]);//父进程关闭写段；
    char buf[10]={0};
    read(fds[0],buf,10);
    printf("receive data= %s\n",buf);
    return 0 ;
}
