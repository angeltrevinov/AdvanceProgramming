#include <stdio.h>

//
// Author: Angel Odiel Treviño Villanueva
// Matricula: A01336559
// Fecha_ 22/08/2019
// A Program that prints the fibonacci sequence without using
//  recursion, the user will tell how many numbers to pring
//

//----------------------------------------------------------
void Fibonacci(
        //Method that displays from the first to the Nth
        //      number of the Fibonacci sequence

        //How many numbers the user wants to print
        int intHowMany
        ) {

   if(intHowMany == 0) {
       return;
   } else if(intHowMany == 1) {
       printf("0 ");
   } else {
       // if the user wants to print more than one number

       printf("0 ");
       int intSum = 0;
       int intPreSum = 0;
       int intPreOldSum = 1;

       for(
               //prints the fibonacci from the first number
               int intContador = 1;
               intContador < intHowMany;
               intContador++
               ) {
           intSum = intPreOldSum + intPreSum;
           intPreOldSum = intPreSum;
           intPreSum = intSum;
           printf("%d ", intSum);
       }
   }
}

//----------------------------------------------------------
int main() {

    int intHowMany;
    printf("How many numbers do you want from the sequence? \n");
    scanf("%d", &intHowMany);

    Fibonacci(intHowMany);

    return 0;
}