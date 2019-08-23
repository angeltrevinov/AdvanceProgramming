#include <stdio.h>

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
           "I can read any number from",
            dDouble,
           sizeof(dDouble)
           );

    return 0;
}

/*
 *An integer
 * Your integer < > storage size is <<size>> bytes.
 * Your char < > storage size is <<size>> bytes. And I can read it as <<display it as character>> or as <<display it as integer>>.
 * Your double < > storage size is <<size>> bytes, I can read any number from <<Min positive value>> to <<Max positive value>> in this data type.
 * */