/*
线程主动结束时，调用清理函数

*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

//清理函数
void mucleanfun(void * arg){
    printf("mycleanfun : %d\n".*((int*)arg));
}

void *thfrunc1( void *arg){
    int m = 1;
    printf(" thfrunc1 comes \n");
    pthread_cleanup_push(mucleanfun,&m);
    return (void*)0;
    pthread_cleanup_pop(0);
}

void *thfrunc( void *arg){
    int m =2 ;
    printf(" thfrunc2 comes :\n");
    phtread_cleanup_push(mucleanfun,&m);
    pthread_exit(0);
    pthread_cleanup_pop(0);
}

int main( void ){

    pthread_t pid1,pid2;
    int res;
    res = pthread_create( &pid1, NULL, thrfrunc1 ,NULL);
    if( res){
        printf(" pthread_create failed: %d\n",strerror(res));
        exit(1);
    }

    //等待进程1结束；
    pthread_join(pid1,NULL);

    //创建进程2；
    res = pthread_create(&pid2 ,NULL, thfrunc,NULL);
    if( res){
        printf(" phthread_create failed: %d\n",strerror(res));
    }
    //等待进程2结束；
    pthread_join(pid2,NULL);
    printf("main over \n");
    return 0;

}