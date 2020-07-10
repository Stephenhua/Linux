#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>
#include <cstdlib>
#include <iostream>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//初始化互斥锁；
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // 初始化条件变量；

void *thread1 ( void *);
void *thread2 ( void *);

int i = 1;

int main(){
    pthread_t t_a ;
    pthread_t t_b ;

    pthread_create(&t_a, NULL ,thread2 , (void*)NULL);
    pthread_create(&t_b ,NULL, thread1 ,(void*)NULL);

    pthread_join(t_b ,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy (&cond);
    exit(0);
}

void *thread2(void *junk){
    while( i < 20){
        
        pthread_mutex_lock(&mutex);
        if( i % 3 != 0){
            pthread_cond_wait(&cond,&mutex);//等待条件变量；
        }

        cout <<"=---------------thread2"<<i<<endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);
        i++;
    }
}

void *thread1(void * junk){
    for( i =1 ;i <=20 ;i++){
        pthread_mutex_lock(&mutex);//锁住互斥锁；

        if( i % 3 == 0 ){
            pthread_cond_signal(&cond);//唤醒条件变量cond的线程；
        }else{
            cout << i <<endl;
        }

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
