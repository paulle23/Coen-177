/*# Name: <Paul Le> 
# Date: <December 2, 2021>
# Title: Lab9 step 4
write operation is made to newly created file for each read operation
time program that copies each file to a new one*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int BUFFSIZE = atoi(argv[2]);//100, 1,000, 10,000 and 100,000 bytes of buffer sizes
    //for file in file1.txt file2.txt file3.txt file4.txt = argv1
    //for buffer in 100 1000 10000 100000 = argv2
    char buffer[BUFFSIZE];
    char* filename = argv[1];
    FILE *outfp = fopen("output", "wb");//prevents translation when writing to file
    fp = fopen(filename, "rb");//open filename and read it
    if (fp == NULL)
    {
        printf("Could not open file %s",filename);//nothing to read
        return 1;
    }
    while (fread(buffer, BUFFSIZE, 1, fp))//else can read from fp to put into buffer and write from outfp onto buffer
        fwrite(buffer, BUFFSIZE, 1, outfp);//write operation is made to a newly created file for each read operation
    fclose(fp);
    fclose(outfp);
    return 0;
}