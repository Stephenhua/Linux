/*
pthread_cleanup_pop调用清理函数

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void myCleanfun( void *arg){
    printf(" myCleanfun1 : %d\n",*((int *)arg));
}

void *thfrunc1(void *arg){
    int m =1 ;
    int n = 2;

    printf(" thfrunc1 comes \n");
    //将清理函数压栈；
    pthread_cleanup_push( myCleanfun,&m);
    //将另一个清理函数压栈；
    pthread_cleanup_push( myCleanfun,&n);
    //出栈清理函数；并执行；
    pthread_cleanup_pop(1);
    //退出线程；
    pthread_exit(0);
    //不会执行，仅仅为了成对；
    pthread_cleanup_pop(0);
}

int main(void){
    pthread_t pid1;
    int res;
    res  = pthread_create(&pid1 ,NULL, thfrunc1,NULL);
    if(res){
        printf("pthread_create faield : %d\n",strerror(res));
    }

    pthread_join(pid1,NULL);
    printf("mian over \n");
    return 0;
}
