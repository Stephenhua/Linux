#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thfunc(void * arg){
    printf("int thefunc\n");
    return (void*)0;
}

int main( int argc ,char*argv[]){

    pthread_t tidp;
    int ret;

    ret = pthread_create( &tidp, NULL , thfunc, NULL) ; //创建进程；
    if( ret){
        printf(" pthread_create failed: %d\n",ret);
        return -1;
    }

    sleep(1);
    printf("int main : thread is created\n");
    return 0 ;
}
