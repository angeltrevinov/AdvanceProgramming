#include <stdio.h>
#include <stdlib.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 13/09/19
 *
 * A KeyLoger in c, to quit press shift+q
 * */

//----------------------------------------------------------
void extremlyLargeString() {

    char cEnter;

    do{
        cEnter = getchar();
        printf("%c", cEnter);
    }while(cEnter != 'Q');

}

//----------------------------------------------------------
int main() {
    printf("Enter your string, to quit enter Q\n");
    extremlyLargeString();
    return 0;
}