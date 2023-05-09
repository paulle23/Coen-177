/*# Name: <Paul Le> 
# Date: <November 17, 2021>
# Title: Lab8 */
//Lab 8, second chance algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct {//to 
    int pageno;
    int second_chance;//added
} ref_page;


int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]); // Size of Cache passed by user 
    ref_page cache[C_SIZE]; // Cache that stores pages 
    char pageCache[100]; // Cache that holds the input from test file
    //
    int totalRequests = 0;
    int j, k, l;
    int found;
    int head = 0;
    //
    int i;
    int totalFaults = 0; // keeps track of the total page faults
    
    for (i = 0; i < C_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
         cache[i].second_chance = 0;
    }

    while (fgets(pageCache, 100, stdin)){//reads from stdin and places first 100 to pagecache
    	int page_num = atoi(pageCache); // Stores number read from file as an int
    	/*
		Page Replacement Implementation Goes Here */
        totalRequests++;
        for(i = 0; i < C_SIZE; i++) {  
            if(cache[i].pageno == page_num) {//page is referenced
                cache[i].second_chance = 1;//set second_chance to 1
                found = 0;//found number, so no fault
                break;
            }
            if(i == C_SIZE-1)//not found and reaches end
                found = 1;//found bit to 1
        }
        if(found) { //not referenced
            //printf("Page %d caused a fault\n", page_num);
            totalFaults++;//more page faults since no reference, now need to add
            for(k = head; k < C_SIZE; k++) {//start at head
                l = k;
                if(cache[l].second_chance == 1) {
                    cache[l].second_chance = 0;//if second chance is 1, set back to 0
                    head++;//move head forward by 1 and increment head if page was not referenced
                    k = 0;//set k back to 0 for when while loop runs again
                    l = (head+k) % C_SIZE;//increment l to k and make sure it is not C_SIZE
                }//if bit is 1, reset to 0 and continue
                //if bit is 0, replace page
                else {//second chance is 0, so replace page
                    cache[l].pageno = page_num;//replace page and set its second chance to 0
                    cache[l].second_chance = 0;
                    head = (head+1) % C_SIZE;//update head when you replace page, moves it forward by 1
                    //also checks if head is greater than C_SIZE with mod so that pointer is not bigger
                    break;
                }
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
