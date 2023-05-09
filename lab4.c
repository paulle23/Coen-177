/*# Name: <Paul Le> 
# Date: <October 14, 2021>
# Title: Lab4 – task 1
# Description: This program runs the helloThread program and deals with threads running in different orders */
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
    static int i;//i is shared between all threads, but arg is per thread
    for (i = 0; i < NTHREADS; i++)
          pthread_create(&threads[i], NULL, go, &i);//creates threads
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);//waits for threads
    printf("Thread %d returned \n", i);
    }
    printf("Main thread done.\n");
}
void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
    return(NULL); 
}
