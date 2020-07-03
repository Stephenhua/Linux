#include <iostream>

using namespace std;

#include <unistd.h>
#include <stdio.h>

int main (){
    pid_t fpid;
    int count = 0 ;
    fpid = fork();

    if( fpid < 0 ){
        cout << "failed to fork;"<<endl;
    }else if( fpid == 0 ){
        cout <<" I am a chilid ,my pid is "<<getpid()<<endl;
        count++;
    }else {
        cout <<" I am a parent proess , my pid is " << getpid() <<endl;
        cout <<"fpid" <<fpid <<endl;
        count++;
    }
    printf("result: %d\n",count);
    return 0;
}