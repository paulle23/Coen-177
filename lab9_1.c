/*# Name: <Paul Le> 
# Date: <December 2, 2021>
# Title: Lab9 step 3
Modify your program in Step 2 to measure the I/O performance 
for 100, 1,000, 10,000 and 100,000 bytes of buffer sizes*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int BUFFSIZE = atoi(argv[2]);//100, 1,000, 10,000 and 100,000 bytes of buffer sizes
    //for file in file1.txt file2.txt file3.txt file4.txt = argv1
    //for buffer in 100 1000 10000 100000 = argv2
    char buffer[BUFFSIZE];
    char* filename = argv[1];
    fp = fopen(filename, "rb");//rb reads non text file
    if (fp == NULL)//if null, cannot opn
    {
        printf("Could not open file %s",filename);
        return 1;
    }//else fread
    while (fread(buffer, BUFFSIZE,1, fp))//reads from fp and places it in str
        printf("%s", buffer);
    fclose(fp);
    return 0;
}