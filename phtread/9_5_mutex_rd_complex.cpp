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
pthread_rwlock_t rwlock;

void * thread_1(void *arg){
    int j ;
    volatile int a;
    for( j = 0 ; j <10000000 ;j++){
        pthread_mutex_lock(&mutex);
        a = gcn;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit((void*)0);
}

void *thread_2(void* arg){
    int j ;
    volatile int b ;
    for( j = 0 ; j < 10000000; j++){
        pthread_mutex_lock(&mutex);
        b = gcn ;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit((void*)0);
}

void *thread_3(void *arg){
    int  j; 
    volatile int a;

    for( j = 0 ; j < 10000000 ;j++){
        pthread_rwlock_rdlock(&rwlock);
        a = gcn ;
        pthread_rwlock_unlock(&rwlock);
    }
    pthread_exit((void*)0);
}

void *thread_4( void *arg){
    int j ; 
    volatile int b ;
    for( j = 0 ; j <10000000 ; j++){
        pthread_rwlock_rdlock(&rwlock);
        b = gcn;
        pthread_rwlock_unlock(&rwlock);
    }
    pthread_exit((void*)0);
}

int mutexVer( void){
    int  j, err;
    pthread_t th1,th2;
    struct timeval start;
    struct timeval end;
    clock_t t1;
    clock_t t2;

    pthread_mutex_init(&mutex,NULL);//初始化互斥锁；

    gettimeofday(&start,NULL);

    err = pthread_create(&th1,NULL,thread_1,strerror(err));

    if( err != 0 ){
        printf("create a new thread error : %s/n",strerror(err));
        exit(0);
    }

    err = pthread_create(&th2, NULL, thread_2,strerror(err));
    if( err != 0 ){
        printf("create a new thread error : %s/n",strerror(err));
        exit(0);
    }

    err = pthread_join(th1,NULL);

    if( err != 0){
        cout <<" wait thread none error :" <<strerror(err)<<endl;
        exit(1);
    }

    err = pthread_join(th2,NULL);
    
    if( err != 0){
        cout <<" wait thread none error :" <<strerror(err)<<endl;
        exit(1);
    }

    gettimeofday(&end, NULL);

    pthread_mutex_destroy(&mutex);

    long long total_time = (end.tv_sec-start.tv_sec)*1000000 +(end.tv_usec - start.tv_usec);
    total_time /= 1000;
    cout <<" mutex time is "<< total_time <<endl;
    return 0;
}

int rdlock(void){
    int j,err;
    pthread_t th1,th2;
    struct timeval start;
    struct timeval end;
    clock_t t1;
    clock_t t2;

    pthread_rwlock_init(&rwlock,NULL);//初始化读写锁；

    gettimeofday(&start,NULL);

    err = pthread_create(&th1,NULL,thread_3,(void*)0);
    if( err != 0){
        cout <<"create new thread error :" <<strerror(err) <<endl;
        exit(0);
    }

    err = pthread_create(&th2,NULL, thread_4,(void*)0);
    if( err != 0){
        cout <<"create new thread error :" <<strerror(err) << endl;
        exit(0);
    }


    err = pthread_join( th1,NULL);
    if( err != 0){
        cout <<" wait thread done error" << strerror(err)<<endl;
        exit(1);
    }

    err = pthread_join(th2,NULL);
    if( err != 0){
        cout <<" wait thread done error" << strerror(err)<<endl;
        exit(1);
    }

    gettimeofday(&end,NULL);

    pthread_rwlock_destroy(&rwlock);

    long long total_time = (end.tv_sec-start.tv_sec)*1000000 +(end.tv_usec - start.tv_usec);
    total_time /= 1000;
    cout <<" mutex time is "<< total_time <<endl;
    return 0;
}

int main(){
    mutexVer();
    rdlock();
    return 0;
}
