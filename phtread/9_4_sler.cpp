#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include <iostream>
using namespace std;

int a = 200;//当前货物价值；
int b = 100;//当前现金；
pthread_mutex_t lock;//全局互斥锁；

void * threadA( void*arg){
    while(1){
        pthread_mutex_lock(&lock);//上锁；
        a -= 50;
        b +=50;
        pthread_mutex_unlock(&lock);
    }
}

void *threadB( void*arg){
    while(1){
        pthread_mutex_lock(&lock);
        cout<<"prices"<<a+b<<endl;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

int main(){
    pthread_t tida,tidb;
    pthread_mutex_init(&lock,NULL);//初始化互斥锁；
    pthread_create(&tida,NULL,threadA,NULL);//创建伙计卖货进程；
    pthread_create(&tidb,NULL,threadB,NULL);

    pthread_join(tida,NULL);//等待进程结束；
    pthread_join(tidb,NULL);
    pthread_mutex_destroy(&lock);//销毁互斥锁；
    return 1;
}
