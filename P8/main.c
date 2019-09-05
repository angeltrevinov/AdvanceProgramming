#include <stdio.h>
#include <float.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 3/09/19
 *
 * A program that uses unions for data
 * */

union UnknownData {
    int intNumber;
    double dNumber;
    char strChar[100];
};

//----------------------------------------------------------
int main() {

    union UnknownData udData;

    /* Integer */
    printf("Enter an integer\n");
    scanf("%d", &udData.intNumber);

    printf("Your integer %d storage size is %lu bytes\n",
           udData.intNumber,
           sizeof(udData.intNumber)
    );

    /* String */
    printf("Enter a string\n");
    scanf(" %s", udData.strChar);

    printf("Your string %s your storage size is %ld "
           "bytes\n",
           udData.strChar,
           sizeof(udData.strChar)
    );

    /* Double */
    printf("Enter your double\n");
    scanf("%lf", &udData.dNumber);

    printf("your double %lf storage size is %ld bytes, "
           "I can read any number from %lf to %lf \n",
           udData.dNumber,
           sizeof(udData.dNumber),
           DBL_MIN,
           DBL_MAX
    );

    /* Union */
    printf("The size of the data is: %lu "
           "bytes\n", sizeof(udData));

    return 0;
}