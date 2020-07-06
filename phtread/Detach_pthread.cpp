#include <pthread.h>
#include <iostream>
using namespace std;

void * thfunc( void *arg){
    cout <<"sub thread is running .\n";
    return nullptr;
}
int main(int argc, char* argv[])
{
    pthread_t  thread_id;
    pthread_attr_t thread_attr;
    struct ched_param  tread_param;
    size_t stack_size;
    int res;
    //线程初始化；
    res = pthread_attr_init( &thread_attr);

    if( res ){
        cout<<" pthread_attr_init failed ："<<res <<endl;
    }
    //设置线程的状态；
    res = pthread_init_setdetachstate( &thread_attr, PTHREAD_CREATE_DETACHED);

    if(res){
        cout <<" PTHREAD+CREATe failed :" <<res <<endl;
    }
    //创建线程；
    res = pthread_create( &thread_id, &thread_attr, thefunc, NULL);

    if( res){
        cout<<" phtread_create failed :" << res <<endl;

    }
    cout <<" main thread will exit\n" <<endl;
    sleep(1);
    return 0;

}