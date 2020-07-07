#ifdef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

#define handle_error_en(en, msg) \  
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0) 
static void * thread_start( void *arg){
    int i,s;
    //定义线程属性结构体；
    pthread_attr_t gattr;

    s = pthread_getattr_np( pthread_self() , &gattr);

    if ( s != 0){
        handle_error_en(s, "pthread_getattr_np") ;
    }
    printf(" Thread's detachstate attribures");

    //从属性结构中获取分离状态属性；
    s = pthread_attr_getdetachstate( &gattr,&i);

    if( s){
        handle_error_en(s,"pthread_attr_getdetachstate");
    }
    //打印当前分离状态属性；
	printf("Detach state        = %s\n",
		(i == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" :  
		(i == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE" :  
		"???"); 
    	 pthread_attr_destroy(&gattr); 
}
int main ( int argc, char* argv[]){
    pthread_t thr;
    int s;
    //创建进程；
    s = pthread_create(&thr,NULL,&thread_start,NULL);
    if( s != 0){
        handle_error_en(s,"pthread_create");
        return 0;
    }
    //等待子进程结束；
    pthread_join(thr,NULL);

    return 0 ;
}
