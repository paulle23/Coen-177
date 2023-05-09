#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>
int main(){
int count = 0;
while(fork()>=0)
{
printf("%d\n",count);
count++;
}
//printf("error\n");
}
