/*# Name: <Paul Le> 
# Date: <December 2, 2021>
# Title: Lab9 step 5*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>

char file_in[20];
int BUFFSIZE, NTHREADS;
 //multiple copies of each file are made.
 //create multiple concurrent multiple threads, 
 //each thread will read and copy a file
 //number of files made = number of threads
void *go(void *arg) {
    char file_out[20];
    char buffer[BUFFSIZE];//buff is number of files
    sprintf(file_out, "files%d.txt", arg);
    //Write formatted output to sized buffer and generate names of new files
    //converts arg into string and stores it in file_out
    //file0.txt to file63.txt = 64 concurrent threads
    FILE *infp=fopen(file_in, "rb");
    FILE *outfp=fopen(file_out, "wb");
    while(fread(buffer, sizeof(char), 1, infp) != 0)
    //if there is stuff to read, write from outfp onto buff
        fwrite(buffer, sizeof(char), 1, outfp);
    fclose(infp);
    fclose(outfp);//close both
}
int main (int argc, char *argv[]){
    strcpy(file_in, argv[1]);//copy argv1 to file_in
    BUFFSIZE = atoi(argv[2]);// number of files made
    NTHREADS = atoi(argv[3]);// number of threads based on a value from the command line “argv[3]”
    //for file in file1.txt file2.txt file3.txt file4.txt = argv1
    //for buffer in 100 1000 10000 100000 = argv2
    //for thread in 2 8 32 64 = argv3
    pthread_t threads[NTHREADS];//create threads
    int i;
    for(i = 0; i < NTHREADS; i++)
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);//create threads
    for(i = 0; i < NTHREADS; i++)
        pthread_join(threads[i],NULL);//wait for the threads
    return 0;
}