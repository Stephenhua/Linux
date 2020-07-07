
#include "unpipc.h" 
  
int main(int argc, char **argv)  
{  
        int c;
	
        int flags = O_RDWR | O_CREAT;  
        mqd_t mqd;

	while ((c = Getopt(argc, argv, "e")) != -1)  
        {  
                switch(c)  
                {  
                        case 'e':  
                                flag |= O_EXCL;  
                                break;  
                }  
        }  
        if (optind != argc -1)  
        {  
                printf("usage: mqcreate [- e] <name>\n");  
                exit(0);  
        }  
        mqd = mq_open(argv[optind], flags, FILE_MODE, NULL);  
       

        Mq_close(mqd);  
        exit(0);  
}  

