/*#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define N 20  //Nthreads 

pthread_t thread_id[N]; 
enum pstate {idle, want_in, in_cs};
enum pstate flag[N];
int turn;
int j;
void leaveCS(int i){
 j = (turn+1) % N;
 while (flag[j]==idle)
    j = (j+1)%N;
 turn = j; 
 flag[i]=idle; 
 printf("Thread %d left Critical Section\n", i);
}

void enterCS(int i){
  while (1) {
     flag[i] = want_in; 
     j = turn;
     while (j != i) {
        if (flag[j] != idle)
           j = turn;
        else
          j = (j+1) % N; 
     }
     flag[i] = in_cs;
     j = 0;
     while ( (j<N) && (j==i || flag[j] != in_cs))
        j++;
     if ( (j>=N) && (turn==i || flag[turn]==idle))
        break; 
  }
  printf("Thread %d entered Critical Section\n", i);
}

void *thread(void* arg) {
 int i = (int)(size_t)arg;
 enterCS(i);
 sleep(5);
 leaveCS(i);
 printf("Goodbye\n");
 return 0;
}

int main(){
 int i;
 for (i = 0; i < N; i++)
   pthread_create(&thread_id[i], NULL, thread, (void*)(size_t)i);
 for (i = 0; i < N; i++)
   pthread_join(thread_id[i], NULL);
 return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#define NTHREADS 2
void *go(void *arg);
pthread_t threads[NTHREADS];

struct d {
 int j;
 int turn;
 bool flag[2];
};

int main() {
 struct d *data = (struct d *) malloc (sizeof(struct d));
 data -> flag[0] = false;
 data -> flag[1] = false;
 int i;
 for (i = 0; i < NTHREADS; i++){
   data -> j = i; 
   pthread_create(&threads[i], NULL, go, data);
   sleep(1);
 }
 for (i = 0; i < NTHREADS; i++) 
   pthread_join(threads[i],NULL);
 return 0;
}

void *go(void *arg) {
 struct d *data = arg;
 int k = data -> j;
 data -> flag[k] = true; 
 data -> turn = !k; 
 sleep(10);
 printf("Thread %d is now attempting ....\n", k);
 while (data -> flag[!k] && data -> turn == !k); 
 printf("Thread %d is running in its Critical Section........\n", k);
 data -> flag[k] = false;
 pthread_exit(0);
}