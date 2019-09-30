#include <stdio.h>
#include <string.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 29/09/2019
 *
 * Mission 3: identified the hashtags inside a downloaded
 * twitter page
 * */

//==========================================================
struct Hashtag {
    char strName[200];
    int intCount;
};

//----------------------------------------------------------
int main() {

    struct Hashtag hashtags[100];
    int intIndex = 0; //limit of our hashtags
    char strWord[100];
    char strFileName[200];
    char strDirectionFile[500] = "/Users/angel/Desktop/ITC/7 Semestre/Programacion Avanzada/AdvanceProgramming/Missions/Mission3/";

    //lets fill our counters with 0
    for(int intCount = 0; intCount < 100; intCount++) {
        hashtags[intCount].intCount = 0;
    }

    printf("Enter your file's name with the file extension\n"
           "remmember to execute terminal commands\n");
    scanf("%s", strFileName);

    FILE* file;
    strcat(strDirectionFile, strFileName);


    file = fopen(strDirectionFile, "rt");

    if(file == NULL) {
        printf("Could not open file %s",strFileName);
        return 1;
    }else  {
        printf("file open");
    }

    return 0;
}

//grep -o -e '(?<=r-qvutc0">#).*(?=</span>)' historia.html > NewHistoria.txt