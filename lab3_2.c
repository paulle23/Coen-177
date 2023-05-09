// Name: Paul Le
// // Date:October 7, 2021
// // Title: Lab3 - task 3
// // Description: This program is similar to step 2 but the writer process passes the ouput of "ls command to the upstream end 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> // main
int main(int argc,char *argv[])
{   
	int  fds[2];   
	char buff[60];   
	int count;   
	int i;   
	pipe(fds);      
	if (fork()==0)
	{       
		printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
		close(fds[0]);
		dup2(fds[1],1);//dup2 for upstream
		execlp("ls","ls",0);//command ls for upstream
		/*for(i=0;i<argc;i++)
		{           
			write(fds[1],argv[i],strlen(argv[i]));       
		} */      
			exit(0);   
	}   
	else if(fork()==0)
	{       
		printf("\nReader on the downstream end of the pipe \n");
       		close(fds[1]);
		dup2(fds[0],0);//dup2 for downstream
		while((count=read(fds[0],buff,60))>0)
		{           
			for(i=0;i<count;i++)
			{               
				write(1,buff+i,1);               
				write(1," ",1);           
			}           
			printf("\n");       
		}       
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
