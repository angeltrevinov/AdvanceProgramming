#include <stdio.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 22/08/2019
 * A program that tells if a given number is prime or not
 * */

void isPrime(int intNumber) {

    if( intNumber <= 1 ) {
        printf("is NOT prime");
        return;
    } else {
        for(int intCount = 2; intCount < intNumber; intCount++) {
            if(intNumber % intCount == 0) {
                printf("is NOT prime");
                return;
            }
        }
    }
    printf("it Is prime");
}

//---------------------------------------------------------
int main() {

    int intNumber;

    printf("Enter your number\n");
    scanf("%d", &intNumber);

    isPrime(intNumber);

    return 0;
}