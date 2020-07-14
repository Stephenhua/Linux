#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h> //for inet_addr
#include "unistd.h"  //for read

int main(){
    int sfp,nfp;

    struct sockaddr_in s_add,c_add;

    socklen_t sin_size;

    unsigned short portnum=10051;

    printf("Hello , I'm a server , Welcome to connect me ! \r \n");

    sfp = socket(AF_INET,SOCK_STREAM,0);

    if( sfp == -1 ){
        printf("socket fail ! \r\n");
        return -1;
    }

    printf("socket ok !\r\n");

    int on = 1;
    setsockopt(sfp,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));//允许地址立即重用；

    bzero(&s_add, sizeof(struct sockaddr_in));

    s_add.sin_family = AF_INET;
    s_add.sin_addr.s_addr = htonl(INADDR_ANY);
    s_add.sin_port=htons(portnum);


    if( bind(sfp,(struct sockaddr*)(&s_add),sizeof(struct sockaddr)) == -1){
        printf("bind fail:%d!\r\n",perror);
        return -1;
    }

    printf("bind ok \r\n");

    if( listen(sfp,5) == -1){
        printf("listen fail! \r\n");
        return -1;
    }
    printf("listen ok .\r\n");

    while(1){
        sin_size = sizeof( struct sockaddr_in);

        nfp = accept( sfp, (struct sockaddr*)(&c_add),&sin_size);

        if( nfp == -1){
            printf("accept fail !\r\n");
            return -1;
        }

        if( -1 == write(nfp,"hello,client,you are welcome!\r\n",32)){
            printf("write fail!\r\n");
            return -1;
        }

        printf("wite ok !\r\n");
        char ch[2];
        scanf("%s",ch,2);//读控制台两个字符；
        if( ch[0] != 'y'){ //如果不是y,就退出循环；
            break;
        }
    }

    printf("bye!\n");
	close(sfp);
	return 0;
}
