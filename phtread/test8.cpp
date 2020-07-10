#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <string.h>
#include <iostream>
#include <chrono> 

using namespace std;



void *thfrunc1(int n){

    std::cout << "thefunc:"<<n <<endl;
}

int main( int argc, const char* argv[]){
    std::thread threads[5];
    cout <<"create 5 thrads..\n";

    for(int i = 0 ; i< 5 ;i++){
        threads[i] = std::thread(thfrunc1,i+1);
    }

    for( auto& t: threads){
        t.join();
    }

    std::cout <<"All thread joined.\n";
    return EXIT_SUCCESS;
}
