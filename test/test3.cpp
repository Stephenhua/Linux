#include <iostream>

using namespace std;

int main(int argc, char*argv[]){
	
	int i ;
	if(argc == 3){
	   cout <<"argc=" << argc <<endl;
	   for(int i =0 ;i <argc ;i++){
	     cout << "argv["<<argv[i] <<"]"<<endl;
	   }
	}else{
	     cout<< "usage :./test3 str1,str2,str3"<<endl;
	}

	return 0;
}
