#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void bar(int *m);
void baz( );
void *go(void *arg);

int main ( ){
 int n = 2;
 bar(&n) ;
 baz( ) ;
 printf("Print 1\n");
 return 0;
}

void bar(int *m) {
 int v = *m;
 pthread_t t2 ;
 pthread_create(&t2, NULL, go, &v);
}

void baz( ) {
 int buffer[1] ;
 buffer[0] = 3;
 pthread_t t1;
 pthread_create(&t1, NULL, go, buffer);
}

void *go(void *arg){
 printf("Print %d\n", *(int *)arg);
 return 0;
} 
