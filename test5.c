#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *waitingForInput(void *);
void *printingPeriod(void*);
pthread_t threads;
int main(int argc, char *argv[]) {
 if (argc != 2){
   printf("Usage: %s <modValue> \n", argv[0]);
   exit(1);
 }
 int modValue = atoi(argv[1]); 
 pthread_create(&threads, NULL, printingPeriod, &modValue);
 pthread_create(&threads, NULL, waitingForInput, NULL);
 pthread_join(threads, NULL);
 return 0;
}

void *printingPeriod(void *arg) {
 int i = 0;
 int modValue = *(int *)arg;
 while(1) {
  if((i % modValue) == 0) 
      printf (".");
  i++;
 }
 return 0;
}

void *waitingForInput(void *arg) {
 char c[1024];
 while (1) {
  printf("Input >> \n");
  if ((scanf("%s", c)) > 0) 
    printf ("\nThank you for your input\n");
 }
 return 0;
}
