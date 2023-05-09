/*# Name: <Paul Le> 
# Date: <November 17, 2021>
# Title: Lab8 */
//Lab 8, least recently used algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//Replace the page that’s been used the least (it’s been in the queue the longest)

typedef struct {//to 
    int pageno;
    int age;//added,Can store a time with each page you store in the queue - a “time stamp” to identify 
//which page has been in the queue the longest
} ref_page;


int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]); // Size of Cache passed by user 
    ref_page cache[C_SIZE]; // Cache that stores pages 
    char pageCache[100]; // Cache that holds the input from test file
    //
    int cacheIndex=0;
    int totalRequests=0;
    int j, k, oldest;
    //
    int i;
    int totalFaults = 0; // keeps track of the total page faults
    
    for (i = 0; i < C_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
         cache[i].age = 0;
    }

    while (fgets(pageCache, 100, stdin)){//puts first 100 from stdin to pagecache
    	int page_num = atoi(pageCache); // Stores number read from file as an int

    	/*
		Page Replacement Implementation Goes Here */
        totalRequests++;
        oldest = cache[i].age;
        for(i = 0; i < C_SIZE; i++) {
            if(cache[i].pageno == page_num) {
                for(j = 0; j < C_SIZE; j++) {                        
                    if(cache[j].age < cache[i].age)
                        cache[j].age++;
                }//increment the age of all of the ones that were not used
                cache[i].age = 0;//reset since it was referenced
                break;
            }
            else if(i == C_SIZE-1) {//if page number not found, not referenced
                //printf("Page %d caused a fault\n", page_num);           
                totalFaults++;  
                for(j = 0; j < C_SIZE; j++) {//increment age of indices that were not used
                    cache[j].age++;
                }
                for(k = 0; k < C_SIZE ; k++) {//then find the oldest
                    if(oldest < cache[k].age){
                        oldest = cache[k].age;//find oldest
                        cacheIndex = k;//find the oldest's index and use that to replace
                    }
                }
                cache[cacheIndex].pageno = page_num;//then replace the oldest
                cache[cacheIndex].age = 0;//reset age since it is new
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
