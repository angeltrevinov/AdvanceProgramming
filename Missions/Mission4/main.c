#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <conio.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 6/10/19
 *
 * Mission 4
 * */

//----------------------------------------------------------
int main() {

    int intX, intY, intRun = 0;

    //the pointer of the file
    FILE *fptr = fopen("Coordinates.txt", "ab+");
    if(fptr == NULL) {
        printf("There was a problem creating the file");
        return -1;
    }

    while(intRun == 0 ) {
        Sleep(100);
        if((GetKeyState(VK_LBUTTON) & 0x80) != 0) {

            POINT Cursor;
            GetCursorPos(&Cursor);
            intX = Cursor.x;
            intY = Cursor.y;

            fprintf(fptr, "positionX: %d, positionY: %d \n", intX, intY);
            printf("positionX: %d, positionY: %d \n", intX, intY);
        } else if((GetKeyState(VK_RBUTTON) & 0x80) != 0) {
            intRun =1;
        }
    }

    fclose(fptr);
    return 0;
}