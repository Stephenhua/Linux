#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
//创建文件；
static char* starter_pid_file_default = "/var/run/test.pid";
//用于检查pid文件夹是否存在；判断进程是否运行；
static bool check_pid(char* pid_file){

    struct stat stb;

    FILE *pidfile;
	//判断文件是否存在；
    if( stat(pid_file,&stb) == 0){
	    //同时用fopen 进行打开；
        pidfile = fopen(pid_file,"r");
        
        if(pidfile){
            pid_t pid = 0;
            char buf[64];
            memset(buf,0,sizeof(buf));
            if( fread(buf,1,sizeof(buf),pidfile)){
                buf[sizeof(buf)-1] = '\0';
                pid=atoi(buf);
            }
            fclose(pidfile);
		//通过kill函数检查进程是否在运行；第二个函数表示准备发送的信号代码：
            if( pid && kill(pid,0) == 0){
                return 1;
            }
        }

        printf("removing pidfile '%s',process not running",pid_file);
        unlink(pid_file);

    }
    return 0;    
}

int main(){
    FILE *fd= fopen( starter_pid_file_default ,"w");
    if( fd){
        fprintf(fd,"%u/n",getpid());
        fclose(fd);
    }

    if( check_pid(starter_pid_file_default)){
        printf("test is already running (%s exists)",starter_pid_file_default);
    }else{
        printf("test is not running (%s not exists)",starter_pid_file_default);
    }
    unlink(starter_pid_file_default);
    return 0 ;
}
