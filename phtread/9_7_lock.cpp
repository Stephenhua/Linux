#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/*
多线程统计到10万；
*/

volatile int counter(0); //定义一个全局变量，当做计数器，用作累加；
std::mutex mtx; //用于保护counter的互斥锁；

void thefunc(){
    for( int i = 0 ;i < 10000 ;i++){
        mtx.lock();//互斥锁上锁；
        ++counter;
        mtx.unlock();//解锁；
    }
}

int main( int argc, const char* argv[]){

    std::thread threads[10];

    for( int i = 0 ;i < 10 ;++i ){
        threads[i] = std::thread(thefunc);//启动线程；
    }

    for( auto &th : threads){
        th.join();//等待线程结束；
    }

    std::cout <<"count to " << counter <<" successfully \n ";
    return 0;
}
