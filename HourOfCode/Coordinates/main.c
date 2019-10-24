#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 24/10/19
 *
 * Hour of Code 3
 * */

struct Coordinates {
    char strTipo[30];
    char strCorDecimal[30];
    char strCorGrados[30];
};

//----------------------------------------------------------
void saveCoordinates(
        int intCont,
        char *strLine,
        struct Coordinates * points
                ) {

    int intI = 0;
    int intPos = 0;

    for(intI = 0; intI < strlen(strLine); intI++){
        if(
                (strLine[intI] >= 'a' &&
                strLine[intI] <= 'z') ||
                strLine[intI] == 'L' ||
                strLine[intI] == ':'
        ) {
            points[intCont].strTipo[intI] = strLine[intI];
        } else {
            break;
        }
    }

    while(strLine[intI + 1] == ' ') {
        intI++;
    }

    intI++;

    while(intI < strlen(strLine)) {
        points[intCont].strCorGrados[intPos] = strLine[intI];
        intPos++;

        if(strLine[intI+1] == ' ') {
            break;
        }

        intI++;
    }

    intPos = 0;
    while(strLine[intI + 1] == ' ') {
        intI++;
    }

    intI++;
    while (intI < strlen(strLine)) {
        points[intCont].strCorDecimal[intPos] = strLine[intI];
        intPos++;
        intI++;
    }
}

//----------------------------------------------------------
void bubbleSort(int Size, struct Coordinates * points) {
    struct Coordinates temp;

    for(int intI = 0; intI < Size - 1; intI++) {
        for(int intJ = 0; intJ < (Size - intI - 1); intJ++){
           if(atof(points[ intJ + 1 ].strCorDecimal) < atof(points[intJ].strCorDecimal)) {
               temp = points[intJ];
               points[intJ] = points[intJ + 1];
               points[intJ + 1] = temp;
           }
        }
    }
}

//----------------------------------------------------------
int main() {

    char strLine[50];
    int intCont = 0;
    struct Coordinates points[100];
    FILE *fptr, *fDecimal, *fGrados;
    fptr = fopen("Coordinates.txt", "r");
    fGrados = fopen("Grados.txt", "w");
    fDecimal = fopen("Decimals.txt", "w");

    while(!feof(fptr)) {
        fgets(strLine, 50, (FILE*)fptr);
        saveCoordinates(intCont, strLine, points);
        intCont++;
    }

    bubbleSort(intCont, points);

    for(int intI = 0; intI < intCont; intI++) {
        fprintf(fGrados, "%s %s\n", points[intI].strTipo, points[intI].strCorGrados);
        fprintf(fDecimal, "%s %lf\n", points[intI].strTipo, atof(points[intI].strCorDecimal));
    }

    printf("Listo");
    fclose(fptr);
    fclose(fDecimal);
    fclose(fGrados);
    return 0;
}