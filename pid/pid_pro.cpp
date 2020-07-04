#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

#define MAXFILE 65535

volatile sig_atomic_t_running = 1 ;

void sigterm_handler( int arg){
    running = 0;
}

int main(){

    pid_t pc;
    int i ,fd,len;
    char * buf = "this is a Demaon\n";

    len = strlen(buf);

    pc = fork();//第一步；

    if( pc < 0){
        printf("error fork\n");
        exit(1);
    }else if( pc > 0){
        exit(0);
    }

    setsid();//第二步；
    chdir("/") ; // 第三步;
    umask(0); //第四步；

    for( int i = 0 ; i < MAXFILE ;i++){
        close(i);
    }

    signal (SIGTERM,sigterm_handler);
    while( _running){
        if( (fd =open("/temp/damon.log", O_CREAT | O_WRONLY | O_APPEND)) < 0){
            perror("open");
            exit(1);
        }
    }

    write(fd ,buf, len+1);
    close(fd);
    usleep(10*1000);
}