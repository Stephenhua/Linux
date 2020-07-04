#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

void sys_err( const char* str){
    perror(str);
    exit(1);
}

int main(void ){
    pid_t pid;
    char* buff[1024];

    int fd[2];
    char* p  = "test  for pipe\n";

    if(pipe(fd) == -1){
        sys_err("pipe");
    }else if( pid == 0 ){
        close(fd[1]);
        printf("child process wait to read::\n");
        int len = read(fd[0],buf,sizeof(buf));
        write(STDOUT_FILRNO,buf,len);
        close(fd[0]);
    }else{
        close(fd[0]);
        write(fd[1],p,strlen(p));
        wait(NULL);
        close(fd[1]);
    }
    return 0;
}
