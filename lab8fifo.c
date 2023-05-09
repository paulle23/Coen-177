/*# Name: <Paul Le> 
# Date: <November 17, 2021>
# Title: Lab8 */
//Lab 8, first in first out 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Replace the page that was placed the first in the queue
typedef struct {//to 
    int pageno;
} ref_page;


int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]); // Size of Cache passed by user 
    ref_page cache[C_SIZE]; // Cache that stores pages 
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    //my added code
    int cacheIndex = 0; 
    int totalRequests = 0;
    //
    for (i = 0; i < C_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int
    	/*
		Page Replacement Implementation Goes Here */
        totalRequests++;
        for(i = 0; i < C_SIZE; i++) {
            if(cache[i].pageno == page_num)
                break;//if found, break
            if(i == C_SIZE-1) {//if not found and full array
                //printf("Page %d caused a fault\n", page_num);
                totalFaults++;//if not found increment total faults
                cache[cacheIndex].pageno = page_num;//input number into array and increment
                cacheIndex = (cacheIndex+1) % C_SIZE;//increments cacheIndex and mods it by C_SIZE if cacheindex is greater
                //cacheindex now points to new oldest page after previous oldest was replaced with new page
            }
        }
    }
    double hitrate = (totalRequests - totalFaults) / (double)totalRequests;
    printf("%d Cache size\n", C_SIZE);
    printf("%d Total Page Faults\n", totalFaults);
    printf("%d Total Page Requests\n", totalRequests);
    printf("%f Hit Rate\n",hitrate);
    return 0;

}
