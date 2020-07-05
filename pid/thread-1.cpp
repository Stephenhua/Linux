//创建进程，返回整形参数
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thfunc(void * arg){
    int *pn = (int*)(arg);
    int n = *pn;

    printf("int thefunc:n=%d\n",n);
    return (void*)0;
}

int main(){
   pthread_t tidp;
   int ret ,n = 110;
   ret = pthread_create(&tidp,NULL,thfunc,&n);
   if(ret){
   	printf("phtread_create failed : %d\n",ret);
	return -1;
   }

   pthread_join(tidp,NULL);//等待子进程移动；
   printf("in main : thread is created \n");
   return 0;

}
