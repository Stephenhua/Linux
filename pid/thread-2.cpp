#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
//创建进程，并传递自负串作为参数；
//
void *thfunc(void * arg){

    char *str;
    str = (char*)arg;//得到传进去的字符；

    printf("int thefunc = %s\n",str);//打印字符串；
    return (void*)0;
}

int main( int argc ,char*argv[]){

    pthread_t tidp;
    int ret;
    const char *str = "hello wordl" ;

    ret = pthread_create( &tidp, NULL , thfunc, (void *)str) ; //创建进程；
    if( ret){
        printf(" pthread_create failed: %d\n",ret);
        return -1;
    }

    pthread_join(tidp,NULL);//等待子线程结束；
    
    printf("int main : thread is created\n");
    return 0 ;
}
