#include <stdio.h>
#include <float.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 22/08/2019
 * A program that displays the different sizes of
 *      types of data.
 * */

//----------------------------------------------------------
int main() {
    int intInteger;
    char charCharacter;
    double dDouble;

    printf("Enter an integer\n");
    scanf("%d", &intInteger);

    printf("Enter a character\n");
    scanf(" %c", &charCharacter);

    printf("Enter your double\n");
    scanf("%lf", &dDouble);

    printf("Your integer %d storage size is %d bytes\n",
            intInteger,
            sizeof(intInteger)
            );
    printf("Your char %c your storage size is %d "
           "bytes. And I can read it as %c or as a %d \n",
           charCharacter,
           sizeof(charCharacter),
           charCharacter,
           charCharacter
           );
    printf("your double %lf storage size is %d bytes, "
           "I can read any number from %lf to %lf",
            dDouble,
           sizeof(dDouble),
           DBL_MIN,
           DBL_MAX
           );

    return 0;
}