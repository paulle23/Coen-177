// Name: Paul Le
// // Date:October 7, 2021
// // Title: Lab3 - task 4
// // Description: This program implements the shell command cat/etc/passwd|grep root
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> // main
int main(int argc,char *argv[])
{   
	int  fds[2];   
	//char buff[60];   
	//int count;   
	//int i;   
	pipe(fds);      
	if (fork()==0)
	{       
		dup2(fds[0],0);//takes what is going downstream and sends it to stdin
		close(fds[1]);//closes upstream end
		execlp("/bin/grep","grep","root",0);   
	}   
	else if(fork()==0)
	{       
		dup2(fds[1],1);//takes what is going upstream and sends it to stdout
		close(fds[0]);//closes downstream end
		execlp("/bin/cat","cat","/etc/passwd",0);  
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
