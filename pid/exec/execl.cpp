#include <unistd.h>

int main(){
 //execl("/bin/pwd","pwd",NULL);
 execl("/bin/ls","ls","-al","/etc/passwd",NULL);
 
 return 0;
}
