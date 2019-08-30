#include <stdio.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 30/08/19
 *
 * A program that does the factorial and fibonacci of a
 *      number using recursion
 * */

//----------------------------------------------------------
int factorial(
        //returns the factorial of the given number
        int intNum
        ) {
    if( intNum == 0) {
        return 1;
    } else {
        return intNum * factorial(intNum-1);
    }
}

//----------------------------------------------------------
int fibonnaci(
        //Returns the nth number of the fibonacci sequence
        int intNum
        ) {

    if(intNum == 0) {
        return 0;
    } else if(intNum == 1) {
        return 1;
    } else {
        return fibonnaci(intNum - 1) + fibonnaci(intNum-2);
    }

}

int main() {
    int intNum;
    printf("Enter the number you want to get the factorial of and fibonacci\n");
    scanf("%d", &intNum);

    printf("**FACTORIAL**\n");
    printf("The factorial of %d is %d \n", intNum, factorial(intNum));
    printf("**FIBONACCI**\n");
    for(int intCount = 0; intCount < intNum; intCount++) {
        printf("%d   ", fibonnaci(intCount));
    }

    return 0;
}