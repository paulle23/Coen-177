//Name: <Paul Le> 
//Date: <September 30>
//Title: Lab2-task3
//Description: This program replaces the processes with two threads 
#include <stdio.h>         
#include <sys/types.h>//pid_t
#include <unistd.h>//fork
#include <stdlib.h>//atoi
#include <errno.h>//errno
#include <pthread.h>//pthread
void* func(void *);

int main(int argc, char *argv[]) 
{
      	if(argc != 2) 
	{
       		printf("Error\n");
       		return 0;
     	}
        pthread_t ptid1, ptid2;//two threads
        int i, m = atoi(argv[1]);//atoi changes argv to integer
	int*n = &m;
        pthread_create(&ptid1, NULL, func,(void *)n);//make two threads
	pthread_create(&ptid2, NULL, func,(void *)n);//has to take in pointer
        pthread_join(ptid1, NULL);//join thread into main process
	pthread_join(ptid2, NULL);
	pthread_exit(NULL);        
     	return 0;
}                              
void* func(void *arg) 
{        
	int i;           
	int *n = (int *)arg;                      
     	for(i = 0; i < 100; i++) 
	{
     		printf("thread %d and thread id is %d\n", i, pthread_self());
		usleep(1000);     	
}
    	return NULL;
}
