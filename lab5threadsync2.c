/*# Name: <Paul Le> 
# Date: <October 14, 2021>
# Title: Lab5 – task 5
# Description: This program runs threadSync.c using mutex locks*/
// Thread Sychronization

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <fcntl.h>//add this for the code to run

#define NTHREADS 10
pthread_t threads[NTHREADS];
pthread_mutex_t lock;//declare lock
sem_t *mutex; 

void* go(void* arg) { 
  pthread_mutex_lock(&lock); //entry section, acquires lock
  printf("Thread %d Entered Critical Section..\n", (int)(size_t)arg); //critical section 
   sleep(1); 
  pthread_mutex_unlock(&lock); //exit section ,lock release
  return (NULL);
} 

int main() { 
//sem_unlink("mutex");
pthread_mutex_init(&lock,NULL);//create lock
static int i;
for (i = 0; i < NTHREADS; i++)  
   pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
for (i = 0; i < NTHREADS; i++) {
   pthread_join(threads[i],NULL);
   printf("\t\t\tThread %d returned \n", i);
   }
printf("Main thread done.\n");
pthread_mutex_destroy(&lock);//delete lock
return 0; 
} 
