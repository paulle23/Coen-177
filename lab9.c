/*# Name: <Paul Le> 
# Date: <December 2, 2021>
# Title: Lab9 step 2
Write a C program to read the files your created in Step 1 from beginning to end, 
then measure how long it takes program to read file*/
#include <stdio.h>

#define SIZE 10000//buffer size
int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[SIZE];//size is 10000
    char* filename = argv[1];
    //for file in file1.txt file2.txt file3.txt file4.txt = argv1
    fp = fopen(filename, "rb");//opens nontext files and reads
    if (fp == NULL)
    {
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fread(buffer, SIZE,1, fp))//if it can read the file
        printf("%s", buffer);//print the buffer
    fclose(fp);//closes file and disassociates it
    return 0;
}