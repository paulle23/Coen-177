/*# Name: <Paul Le> 
# Date: <November 17, 2021>
# Title: Lab8 */
//generates testinput.txt
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer [sizeof(int)];
    int i;
    fp = fopen("testInput.txt", "w");
    for (i=0; i<20; i++){
        sprintf(buffer, "%d\n", rand()%20);
        fputs(buffer, fp);
    }
    fclose(fp);
    return 0;
}