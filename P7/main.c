#include <stdio.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 30/08/19
 *
 * A program that changes the vocals to different numbers
 * */

//----------------------------------------------------------
void changeWord(
        //Method that changes the vocals from the string
        //      to numbers
        char *strWord
        ) {

    for(int intCount = 0; intCount < sizeof(strWord); intCount++) {

        if(strWord[intCount] == 'a' ) {
            strWord[intCount] = '4';
        } else if(strWord[intCount] == 'e') {
            strWord[intCount] = '3';
        } else if(strWord[intCount] == 'i') {
            strWord[intCount] = '1';
        } else if(strWord[intCount] == 'o') {
            strWord[intCount] = '0';
        } else if(strWord[intCount] == 'u') {
            strWord[intCount] = '2';
        }
    }

}

int main() {
    char strWord[200];
    printf("Enter the word you want to change\n");
    scanf("%s", strWord);
    changeWord(strWord);
    printf("The new word is: %s", strWord);
    return 0;
}