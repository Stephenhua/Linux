#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int gcn = 0 ;
pthread_mutex_t mutex;

void * thread_1 ( void *arg){
    int j ;
    for(int j = 0 ;j < 10000000;j++){
        
        pthread_mutex_lock(&mutex);
        gcn++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit((void*)0);
}

void *thread_2( void *arg){
    int  j;
    for(int j = 0 ;j <1000000 ; j++){
        pthread_mutex_lock(&mutex);
        gcn++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit((void*)0);
}


int main(void){
    int j ,err;
    pthread_t th1,th2;

    pthread_mutex_init(&mutex,NULL);//初始化互斥锁；

    for( int j = 0 ; j <10 ;j++){
        err = pthread_create(&th1,NULL,thread_1,(void*)0);
        if(err != 0){
            cout <<" create new thread err:"<<strerror(err)<<endl;
            exit(0);
        }

        err = pthread_create(&th2,NULL, thread_2,(void*)0);
        if( err != 0){
            cout << pthread_create(&th2, NULL, thread_2 ,(void*)0);
        }
        if(err != 0){
            cout <<" create new thread err:"<<strerror(err)<<endl;
            exit(0);
        }

        err = pthread_join( th1 ,NULL);

        if( err != 0){
            printf("waite thread done error:%s\n",strerror(err));
        }

        err = pthread_join( th2, NULL);

        if( err != 0){
            printf( " waite thread done error : %s\n", strerror(err));
        }

        printf("gcn  = %d \n",gcn);
	gcn = 0;        
    }

    pthread_mutex_destroy(&mutex);//销毁互斥锁；
    return 0 ;
}
