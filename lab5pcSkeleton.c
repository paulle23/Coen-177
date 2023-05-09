/*# Name: <Paul Le> 
# Date: <October 14, 2021>
# Title: Lab5 – task 6
# Description: This program runs the producer consumer program with semaphores */
// Producer - Consumer with semaphores

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>//add this for signal

#define BUFSIZE 10
#define NP 3 
#define NC 2

pthread_t tidP[NP], tidC[NC];   
int buff[BUFSIZE];
sem_t *mutex, *full, *empty; 
int p, c, in, out; 

void *producer(void *arg) {
    int item;
    int p = (int)(size_t)arg;//add size_t
    srand(time(0));
    do {
        item = (rand() % 100);  // random number for producer
        sem_wait(empty);//waits for consumer to empty buffer if full
        sem_wait(mutex);//lock acquire
       //your code to add item to buffer and increment in index
       buff[in] = item;
       in = (in+1)%BUFSIZE;
        printf ("Producer #: %d produced item: %d at buffer space: %d\n", p, item, in);
        sleep(5);
        
        sem_post(mutex);//lock release
        sem_post(full);//release if buff is full
    } while (1);
    pthread_exit(0);
}

void *consumer(void *arg) {
    int item;
    int c = (int)(size_t)arg;//add size_t
    srand(time(0));
    do {
        sem_wait(full);//wait for producer to fill buffer if not full 
        sem_wait(mutex);//acquire lock when full
        //you code to remove next item from buffer and increment out index
        item=buff[out];
        out = (out+1)%BUFSIZE;

        printf ("\t\t\tConsumer #: %d consumed item: %d at buffer space: %d\n", c, item, out);
        sleep(10);	
        sem_post(mutex);//release lock
        sem_post(empty);//release if buff is empty and there is nothing to get
    } while (1);
    pthread_exit(0);
}

void cleanup(int sigtype){
    printf("\n Terminating\n");
    //destroy semaphores before terminating
    sem_unlink("mutex");
    sem_unlink("empty");
    sem_unlink("full");
    exit(0);
}

int main () {
    signal(SIGINT,cleanup); 
    //your code to create mutex, empty, and full semaphores 
    // Initialize/Open our three shared variables
    mutex = sem_open("mutex", O_CREAT, 0644, 1);
    empty = sem_open("empty", O_CREAT, 0644, BUFSIZE);
    full = sem_open("full", O_CREAT, 0644, 0);  
    for (p = 0; p < NP; p++)
        pthread_create (&tidP[p],NULL,producer,(void*)(size_t)p);//your code to pass argument to producer thread);
    for (c = 0; c < NC; c++)
        pthread_create (&tidC[c],NULL,consumer,(void*)(size_t)c);//your code to pass arguments to consumer thread);
   // main thread waiting for consumer and producer threads to complete their tasks
    for (p = 0; p < NP; p++) {
        pthread_join(tidP[p],NULL);
        printf("Producer thread %d returned\n", p);
    }
    for (c = 0; c < NC; c++) {
        pthread_join(tidC[c],NULL);
        printf("\t\t\tConsumer thread %d returned\n", c);
    }
    printf("Main thread finished\n");
    //destroy semaphores
    sem_unlink("mutex");
    sem_unlink("empty");
    sem_unlink("full");
    return 0;
}