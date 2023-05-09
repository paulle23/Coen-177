//Name: <Paul Le>
//Date: <September 30>
//Title: Lab2-task4
//Description: This program is the same as task 1 except that the child process runs the ls command and the parent waits for the child to terminate for exiting
/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) 
{
    if(argc != 2)
    {
        printf("Error\n");
        return 0;
    }
    pid_t  pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay    	
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) 
    {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    else if(pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child Complete");
        exit(0);
    }
    return 0;
}
