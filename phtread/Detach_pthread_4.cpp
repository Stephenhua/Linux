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

//将可接线程转为可分离线程；

static void* thread_start( void * arg){
    int i,s;
    pthread_attr_t gattr;
    //获取当前线程属性值；
    s = pthread_getattr_np( pthread_self(), &gattr);
    if(s){
        printf(" pthread_getattr_np failed. \n ");
    }
    //从属结构值中获取分离状态属性
    s = pthread_attr_getdetachstate(&gattr, &i);

    if(s){
        printf(" phtread_attr_getdetachstate failed.\n");
    }

	printf("Detach state        = %s\n",
		(i == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" :  
		(i == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE" :  
		"???");  
    //转换线程为肯分离线程；
    pthread_detach(pthread_self());
    s = pthread_getattr_np(pthread_self(), &gattr);
    //获取当前属性值；
    if( s != 0){
        printf("pthread_getattr_np failed \n");
    }
    //从属性结构中获取分离状态属性；
    s = pthread_attr_getdetachstate(&gattr, &i );

    if(s){
        printf(" pthread_attr_getdetachstate failed");
    }

    printf("after pthread_detech \n,Detach state =%s\n",		(i == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" :  
		(i == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE" :  
		"???");  
    
    pthread_attr_destroy( &gattr);

}

int main( int argc, char* argvp[]){
 	pthread_t thread_id;  
	int s;  
 
	s = pthread_create(&thread_id, NULL, &thread_start, NULL);  
	if (s != 0)  
	{
		printf("pthread_create failed\n"); 
		return 0;
	}
	pthread_exit(NULL);//主线程退出，但是并不是代表线程将会退出；   
}
