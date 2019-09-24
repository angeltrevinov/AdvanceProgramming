
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <MacTypes.h>
#include <ctype.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 23/09/19
 * */

//----------------------------------------------------------
Boolean  validarAgente(char *strIdAgente) {

    for(int intPos = 0; intPos < 13; intPos++) {

        //We are working with the first letters
        if(intPos < 4){
            if(!(
                    (strIdAgente[intPos] >= 'a' &&
                     strIdAgente[intPos] <= 'z') ||
                    (strIdAgente[intPos] >= 'A' &&
                     strIdAgente[intPos] <= 'Z')
            )){
                return false;
            }
        } else if (
            //If its not a number, break
                !(strIdAgente[intPos] >= '0' &&
                  strIdAgente[intPos] <= '9')) {
            return false;

        }

    }

    return true;

}

//----------------------------------------------------------
void changeData(char strId[14], char* strNumeros) {

    char* strVariable;
    char* strNew;
    char cBetween;
    char strNewId[14];
    int intCont = 0;
    int intCont2 = 0;
    int intContNew = 0;
    int intSize = strlen(strNumeros);
    strNew = (char*)malloc(sizeof(char)*10);

    do{
        strVariable = strNumeros;
        intCont = 0;

        //separate numbers
        while(*strNumeros != ',' && intCont2 < intSize){
            if(*strNumeros == ' ') break;
            intCont++;
            intCont2++;
            strNumeros++;
        }

        cBetween = *strNumeros;
        strNumeros++;
        intCont2++;
        *(strVariable + intCont) = '\0';

        //check the values and return the number as an int
        if(strcmp(strVariable, "cero")  == 0) {
            *(strNew + intContNew) = '0';
            intContNew++;
        } else if(strcmp(strVariable, "uno") == 0){
            *(strNew + intContNew) = '1';
            intContNew++;
        } else if(strcmp(strVariable, "dos") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
        } else if(strcmp(strVariable, "tres") == 0) {
            *(strNew + intContNew) = '3';
            intContNew++;
        } else if(strcmp(strVariable, "cuatro") == 0) {
            *(strNew + intContNew) = '4';
            intContNew++;
        } else if(strcmp(strVariable, "cinco") == 0) {
            *(strNew + intContNew) = '5';
            intContNew++;
        } else if(strcmp(strVariable, "seis") == 0) {
            *(strNew + intContNew) = '6';
            intContNew++;
        } else if(strcmp(strVariable, "siete") == 0) {
            *(strNew + intContNew) = '7';
            intContNew++;
        } else if(strcmp(strVariable, "ocho") == 0) {
            *(strNew + intContNew) = '8';
            intContNew++;
        } else if(strcmp(strVariable, "nueve") == 0) {
            *(strNew + intContNew) = '9';
            intContNew++;
        } else if(strcmp(strVariable, "diez") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '0';
            intContNew++;
        } else if(strcmp(strVariable, "once") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '1';
            intContNew++;
        } else if(strcmp(strVariable, "doce") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '2';
            intContNew++;
        } else if(strcmp(strVariable, "trece") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '3';
            intContNew++;
        } else if(strcmp(strVariable, "catorce") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '4';
            intContNew++;
        } else if(strcmp(strVariable, "quince") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '5';
            intContNew++;
        } else if(strcmp(strVariable, "dieciseis") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '6';
            intContNew++;
        } else if(strcmp(strVariable, "diecisiete") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '7';
            intContNew++;
        } else if(strcmp(strVariable, "dieciocho") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '8';
            intContNew++;
        } else if(strcmp(strVariable, "diecinueve") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '9';
            intContNew++;
        } else if(strcmp(strVariable, "veinte") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '0';
            intContNew++;
        } else if(strcmp(strVariable, "veintiuno") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '1';
            intContNew++;
        }  else if(strcmp(strVariable, "veintidos") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '2';
            intContNew++;
        }  else if(strcmp(strVariable, "veintitres") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '3';
            intContNew++;
        }  else if(strcmp(strVariable, "veinticuatro") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '4';
            intContNew++;
        }  else if(strcmp(strVariable, "veinticinco") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '5';
            intContNew++;
        }  else if(strcmp(strVariable, "veintiseis") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '6';
            intContNew++;
        }  else if(strcmp(strVariable, "veintisiete") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '7';
            intContNew++;
        }  else if(strcmp(strVariable, "veintiocho") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '8';
            intContNew++;
        }  else if(strcmp(strVariable, "veintinueve") == 0) {
            *(strNew + intContNew) = '2';
            intContNew++;
            *(strNew + intContNew) = '9';
            intContNew++;
        }  else if(strcmp(strVariable, "treinta") == 0) {
            if(cBetween == ',') {
                *(strNew + intContNew) = '3';
                intContNew++;
                *(strNew + intContNew) = '0';
                intContNew++;
            } else {
                *(strNew + intContNew) = '3';
                intContNew++;
            }
        } else if(strcmp(strVariable, "cuarenta") == 0) {
            if(cBetween == ',') {
                *(strNew + intContNew) = '4';
                intContNew++;
                *(strNew + intContNew) = '0';
                intContNew++;
            } else {
                *(strNew + intContNew) = '4';
                intContNew++;
            }
        } else if(strcmp(strVariable, "cincuenta") == 0) {
            if(cBetween == ',') {
                *(strNew + intContNew) = '5';
                intContNew++;
                *(strNew + intContNew) = '0';
                intContNew++;
            } else {
                *(strNew + intContNew) = '5';
                intContNew++;
            }
        } else if(strcmp(strVariable, "sesenta") == 0) {
            if(cBetween == ',') {
                *(strNew + intContNew) = '6';
                intContNew++;
                *(strNew + intContNew) = '0';
                intContNew++;
            } else {
                *(strNew + intContNew) = '6';
                intContNew++;
            }
        } else if(strcmp(strVariable, "setenta") == 0) {
            if(cBetween == ',') {
                *(strNew + intContNew) = '7';
                intContNew++;
                *(strNew + intContNew) = '0';
                intContNew++;
            } else {
                *(strNew + intContNew) = '7';
                intContNew++;
            }
        } else if(strcmp(strVariable, "ochenta") == 0) {
            if(cBetween == ',') {
                *(strNew + intContNew) = '8';
                intContNew++;
                *(strNew + intContNew) = '0';
                intContNew++;
            } else {
                *(strNew + intContNew) = '8';
                intContNew++;
            }
        } else if(strcmp(strVariable, "noventa") == 0) {
            if(cBetween == ',') {
                *(strNew + intContNew) = '9';
                intContNew++;
                *(strNew + intContNew) = '0';
                intContNew++;
            } else {
                *(strNew + intContNew) = '9';
                intContNew++;
            }
        } else if(strcmp(strVariable, "cien") == 0) {
            *(strNew + intContNew) = '1';
            intContNew++;
            *(strNew + intContNew) = '0';
            intContNew++;
            *(strNew + intContNew) = '0';;
            intContNew++;
        }

        *(strNew + 9) = '\0';

    }  while (intCont2 < intSize);

    strcpy(strNewId, strId);
    strNew += 8;

    for(int intI = 4; intI < 13; intI++) {
        strNewId[intI] = *strNew;
        strNew--;
    }

    printf("The new Id: %s\n", strNewId);
}

//----------------------------------------------------------
int main() {

    char strIdAgente[14];
    char strNumeros[50];
    char* p; //apuntador al numero


    //ask for Agents id
    do{
        printf("Enter your Agent's id\n");
        scanf("%s", strIdAgente);

    }while (!validarAgente(strIdAgente));

    printf("Enter the numbers separated with ,\n");
    fflush(stdin);  //Vaciar el buffer
    scanf(" %[^\n]s", strNumeros);
    //strlwr not part of the standard c99
    for(int intCon = 0; intCon < strlen(strNumeros); intCon++) {
        strNumeros[intCon] = tolower(strNumeros[intCon]);
    }

    p = strNumeros;
    changeData(strIdAgente, p);

// 1, 55, 9, 0, 16, 20
    return 0;
}