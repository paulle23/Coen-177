/*COEN 146L : Lab1 - Step 5&6*/
// Name: Paul Le
// Date: 1/14/22
// Title: Lab1 – task 5
// Description: This program works with circuit switching and packet switching scenarios
#include <stdio.h>  
#include <math.h>
#include <stdlib.h>

double factorial(double n)
{
    //factorial function
    double result = 1;
    int i = 1;
    for(i = n; i > 1; --i)
    {
        result = (result * i);
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc !=5){
	fprintf(stderr,"usage: ./a.out <linkBandwidth> <userBandwidth> <tPSusers> <nPSusers> \n");
	exit(0);
    } 
   int i, linkBandwidth, userBandwidth, nCSusers, nPSusers;
   double pPSusers, tPSusers, pPSusersBusy, pPSusersNotBusy;
   
   // Get values from command line
   linkBandwidth = atoi(argv[1]);
   userBandwidth = atoi(argv[2]);
   tPSusers  = atof(argv[3]);
   nPSusers = atoi(argv[4]);

   // 5a: Circuit Switching Senario
   // how many users --> nCSusers
   nCSusers = linkBandwidth/userBandwidth;
   printf("5a: Circuit switching senario: %d users\n", nCSusers);
   
   // 6: Packet Switching Senario
   /* compute: 6a, b, c, d, e, f, g, h 
   pPSusers = 
   pPSusersNotBusy = 
   double pAllNotBusy = 
   double pOneBusy = 
   double pExactlyOne = 
   double pTenBusy = 
   double pAnyTenBusy = 
   double pTenMoreBusy = 
   
   */
   printf("6: Packet switching senario");
   pPSusers = tPSusers;
   printf("6a: The probability that a given (specific) user is busy transmitting = %f\n", pPSusers);
   pPSusersNotBusy = 1 - pPSusers;
   printf("6b: The probability that ine specific other user is not busy =  %f\n", pPSusersNotBusy);
   double pAllNotBusy = pow((1 - pPSusers),(nPSusers - 1));
   printf("6c: The probablility that all of the other specific other users are not busy =  %e\n", pAllNotBusy);
   double pOneBusy = pPSusers * pow(pPSusersNotBusy,(nPSusers-1));
   printf("6d: The probability that one specific user is transmitting and the remianing users are not transmitting =  %e\n", pOneBusy);
   double pExactlyOne = nPSusers * pOneBusy;
   printf("6e: The probability that exactly one of the nPSusers users is busy is pPSusers times the probability that a given specific user is transmitting and the remaining users are not transmitting = %le\n", pExactlyOne);
   double pTenBusy = pow(pPSusers,10) * pow(pPSusersNotBusy, (nPSusers-10));
   printf("6f: The probabalitiy that 10 specific users of nPSusers are transmitting and the others are idle = %lg\n", pTenBusy);
   double coefficient = factorial(nPSusers)/factorial(10)/factorial(nPSusers - 10);
   double pAnyTenBusy = coefficient * pTenBusy;
   printf("6g: The probability that any 10 users of nPSusers are transmitting and the others are idle = %lg\n", pAnyTenBusy);
   double pTenMoreBusy = 0;
   for(i = 11; i <= nPSusers; ++i){
     double countUsers = pow(pPSusers, i) * pow(pPSusersNotBusy, nPSusers - i);
     double combos = factorial(nPSusers)/ factorial(i) /factorial(nPSusers - i);
     pTenMoreBusy += countUsers * combos;
   }
   printf("6h: The probability that more than 10 users of nPSusers are transmitting and the others are idle = %lg\n", pTenMoreBusy);
   return 0;
}