
//传递结构体参数；
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

//定义结构体类型；
typedef struct{
    int n ;
    char * str;

}MYSTRUCT;

void *thfunc(void * arg){

    MYSTRUCT *p = (MYSTRUCT*) arg;//创建结构体；

    printf("int thefunc : n = %d , str=%s\n",p->n,p->str);//打印字符串；
    return (void*)0;
}

int main( int argc ,char*argv[]){

    pthread_t tidp;
    int ret;
    MYSTRUCT mystruct;
    mystruct.n  = 110;
    mystruct.str = "hello, word";

    ret = pthread_create( &tidp, NULL , thfunc, (void *)&mystruct) ; //创建进程；
    if( ret){
        printf(" pthread_create failed: %d\n",ret);
        return -1;
    }

    pthread_join(tidp,NULL);//等待子线程结束；
    
    printf("int main : thread is created\n");
    return 0 ;
}
