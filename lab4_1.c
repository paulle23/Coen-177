/*# Name: <Paul Le> 
# Date: <October 14, 2021>
# Title: Lab4 – task 2
# Description: This program runs the helloThread program and deals with threads running in different orders but removes the second loop */
/**************************************************************
 * *threadHello.c - simple multi-threaded program.            *
 * *   compile with: >gcc -lp threadHello.c -o threadHello       *                    
 * ***************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define NTHREADS 20
void *go(void *);
pthread_t threads[NTHREADS];
int main() {
    static int i;
    for (i = 0; i < NTHREADS; i++)
          pthread_create(&threads[i], NULL, go, &i);
    printf("Main thread done.\n");
}
void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
    return(NULL); 
}
