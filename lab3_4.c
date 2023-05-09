// Name: Paul Le
// // Date:October 7, 2021
// // Title: Lab3 - task 5
// // Description: This program implements the producer-consumer message communication using pipes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 
int main(int argc,char *argv[])
{   
	int  fds[2];   
	char buff[60];
	char buffer[60];//buffer is temporary storage used to store input and output commands   
	int count;   
	int i;   
	pipe(fds);      
	if (fork()==0)
	{      //argc is the number of arguments 
		printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
		close(fds[0]);       
		for(i=1;i<argc;i++)
		{           
			//write(fds[1],argv[i],strlen(argv[i])); 
			strcat(buffer,argv[i]);//put argv into buffer      
		}//writes buffer
		write(fds[1],buffer,strlen(buffer));       
		exit(0);   
	}   
	else if(fork()==0)
	{       
		printf("\nReader on the downstream end of the pipe \n");
       		close(fds[1]);
		read(fds[0],buffer,60);//reads input and puts into buffer
		printf("\n");
		write(1,buffer,60);//1 is stdout
		printf("\n");
		/*while((count=read(fds[0],buff,60))>0)
		{           
			for(i=0;i<count;i++)
			{               
				write(1,buff+i,1);               
				write(1," ",1);           
			}           
			printf("\n");       
		} */      
		exit(0);    
	}   
	else
	{           
		close(fds[0]);      
		close(fds[1]);      
		wait(0);      
		wait(0);   
	}
	return 0;
}
