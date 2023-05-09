/*# Name: <Paul Le> 
# Date: <November 17, 2021>
# Title: Lab8 */
//generates testinput.txt with 10k
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer [sizeof(int)];
    int i;
    fp = fopen("testInput10k.txt", "w");
    for (i=0; i<10000; i++){
        sprintf(buffer, "%d\n", rand()%20);
        fputs(buffer, fp);
    }
    fclose(fp);
    return 0;
}