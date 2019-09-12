#include <stdio.h>
#include <math.h>
#include <string.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 06/09/19
 *
 * A program that does a lot of Pointers and arrays arithmetic
 * */

//----------------------------------------------------------
int asciiBinaryToInt(
        //Method that receives a string binary and returns
        //      the value of the binary as an int
        char *strBinary
        ) {

    int intSum = 0;
    int intCount = strlen(strBinary) - 1;

    while((*strBinary == '0') || (*strBinary == '1')) {

        if(*strBinary == '1') {
            intSum = intSum + pow(2, intCount);
        }

        strBinary++;
        intCount--;
    }

    return intSum;
}

//----------------------------------------------------------
int asciiHEXToInt(
        //Method that receives a string hex and returns the
        //      the value of the hex as the int value
        char *strHex
        ) {

    int intSum = 0;
    for(int intCount = strlen(strHex) - 1; intCount >= 0; intCount--) {

        if(*strHex >= '0' && *strHex <= '9') {
            intSum = intSum + (*strHex - '0') * pow(16, intCount);
        } else if(*strHex == 'A' || *strHex == 'a') {
            intSum = intSum + 10 * pow(16, intCount);
        } else if(*strHex == 'B' || *strHex == 'b') {
            intSum = intSum + 11 * pow(16, intCount);
        } else if(*strHex == 'C' || *strHex == 'c') {
            intSum = intSum + 12 * pow(16, intCount);
        } else if(*strHex == 'D' || *strHex == 'd') {
            intSum = intSum + 13 * pow(16, intCount);
        } else if(*strHex == 'E' || *strHex == 'e') {
            intSum = intSum + 14 * pow(16, intCount);
        } else if(*strHex == 'F' || *strHex == 'f') {
            intSum = intSum + 15 * pow(16, intCount);
        }

        strHex++;
    }

    return intSum;

}

//----------------------------------------------------------
double asciiToDouble(
        //Does operations from ASCII input
        char *strASCII
        ) {

    double dSum = 0;
    int intNext = 1;

    while(*strASCII == '-' || *strASCII == '+') {

        if(*strASCII == '-') {
            intNext = -1;
        }
        strASCII++;
    }

    while(*strASCII >= '0' && *strASCII <= '9') {
        dSum = (dSum * 10) + (*strASCII - '0');
        strASCII++;
    }

    return dSum * intNext;
}

//----------------------------------------------------------
int main() {
    int intOption;
    char strBinary[32];
    char strHex[8];
    char strASCII[32];

    do {
        printf("********************\n"
               "Choose which option to do: \n"
               "1. Convert from binary to int\n"
               "2. Convert Hex to int\n"
               "3. Conver ASCII to int\n"
               "4. Exit Program\n");
        scanf("%d", &intOption);

        if(intOption == 1) {
           printf("Enter your binary\n");
           scanf("%s",strBinary);

           printf("The value of your Binary is: %d\n",
                   asciiBinaryToInt(strBinary)
                   );
        } else if(intOption == 2) {

            printf("Enter your hex value\n");
            scanf("%s", strHex);

            printf("The value of your Hex is: %d\n",
                    asciiHEXToInt(strHex)
                    );
        } else if(intOption == 3) {
            printf("Enter your ASCII to conver\n");
            scanf("%s", strASCII);

            printf("Your result is: %d\n",
                    asciiToDouble(strASCII)
                    );

        }

    } while(intOption != 4);

    return 0;
}