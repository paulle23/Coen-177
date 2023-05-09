//Name: <Paul Le>
//Date: <September 30>
//Title: Lab2-task2
//Description: This program creates 7 process, with each process creating two children or none
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h> 
int main()
{
	int children = 6;
	printf("The original process is: %d\n", getpid());
    	while(children > 0)
	{
	if(fork() == 0)
	{
		printf("This process is pid= %d, the parent process is ppid= %d\n", getpid(), getppid());
		break;
	}
	else
	{
		waitpid(-1,NULL,0);
	}
	if(fork()!=0)
	{
		waitpid(-1,NULL,0);
		break;
	}
	else
	{
	printf("This process is pid= %d, the parent process is ppid= %d\n", getpid(), getppid());
    	}
		children = children - 2;	
	} 
 	return 0;
}
