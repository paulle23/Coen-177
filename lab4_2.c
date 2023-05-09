/*# Name: <Paul Le> 
# Date: <October 14, 2021>
# Title: Lab4 – task 3
# Description: This program does matrix multiplication with threads using parallel matrix multiply */
// Lab4 - skeleton for step 3
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>//values of N,M, and L 
#define N 4
#define M 4
#define L 4
pthread_t threads[N];
//A, B, C matrices
double matrixA[N][M], matrixB[M][L], matrixC[N][L];
//function prototypes
void initializeMatrix(int r,int c, double matrix[r][c]);
void *multiplyRow(void* arg);
void printMatrix(int r,int c, double matrix[r][c]);
int main(){
	int i;
	initializeMatrix(N, M, matrixA);  //initilaize matrixA with random values
	initializeMatrix(M, L, matrixB); //initialize matrixB with random values
	//create N threads, each multiplying row A by all columns fo B to produce rowof C
	////your code
	for(i=0;i<N;i++)//calls multiplyRow
		pthread_create(&threads[i],NULL,multiplyRow,(void*)(size_t)i);
	////Main thread waits for child threads to complete
	for(i=0;i<N;i++){
		pthread_join(threads[i],NULL);
	}//Print Matrix A, B, and C
	//your code
	printf("Matrix A\n");//print each matrix with the header before
	printMatrix(N,M,matrixA);
	printf("Matrix B\n");
	printMatrix(M,L,matrixB);
	printf("Matrix C\n");
	printMatrix(N,L,matrixC);	
	return 0;
}
	//Initialize matrixA and matrixB with random values
void initializeMatrix(int r,int c, double matrix[r][c]){
	srand(time(NULL));
	//your code
	int i,j;
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++)
			matrix[i][j] = rand() % 20;//initializes the matricies with a random number
	}
}
	//thread function: multiply row of A by columns of B --> row of C
void* multiplyRow(void* arg){
	//your code, multiplication is correct, work on printing it
	int i = (int)(size_t)arg;//make a variable integer i from (void*)(size_t)i
	int j,k;
	for(j = 0;j<L; j++){
		double temp = 0;
		for(k = 0; k < M; k++){
			temp += matrixA[i][k]*matrixB[k][j];
		}
	matrixC[i][j] = temp;
	} //
	return 0;
}
	//Print matrices
void printMatrix(int r,int c, double matrix[r][c]){
	int i, j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%lf ",matrix[i][j]);
		printf("\n");
	}
}
