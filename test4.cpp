#include <iostream>
using namespace std;
void zww(int age){
    int a,b,c;
    if( age  > 60 ){
        cout <<"i am old "<<endl;
    }else{
        cout <<"i am not a old "<<endl;
    }
}
int main (){
    int a = 5;
    int b = 6;
    zww(70);
    a++;
    b++;
    if( a > b){
        cout<< a <<endl;
    }else{
        cout << b <<endl;
    }
    return 0 ;
}