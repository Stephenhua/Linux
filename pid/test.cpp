#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc,char*argv[])
{
	pid_t pid ;
	cout <<sizeof(pid_t) <<endl;
	
	cout<<"pid=" << pid <<endl;
	
	return 0;
}
