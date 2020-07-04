#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

int main(void ){
    pid_t childpid;
    int status;
    int retval;

    childpid = fork();

    if( childpid == -1){
        perror("fork()");
        exit(EXIT_SUCCESS);
    }else if( childpid == 0){
        puts("In child process");
        sleep(100);//让子进程休眠，以便查看父进程行为；
    }else {

        if( waitpid(childpid,&status,WNOHANG)){// 判断子进程是否退出
            retval = kill(childpid,SIGKILL);//发送sigkill信号给子进程，要求其停止运行

            if(retval){
                //判断是否发生信号；
                puts("kill failes") ;//失败；
                perror("kill");
                waitpid(childpid,&status,0);
            }else{
                printf("%d killed \n",childpid);
            }
        }
    }
    exit(EXIT_SUCCESS);
}