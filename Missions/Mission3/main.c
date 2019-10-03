#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
    char strWord[100];
    char strFileName[200];
    int intIndex = 0;
    /* You should change this for your own location*/
    char strDirectionFile[500] = "/Users/angel/Desktop/ITC/7 Semestre/Programacion Avanzada/AdvanceProgramming/Missions/Mission3/";
    char strPatternbefore[500] = "r-qvutc0\">#";
    char strPatternAfter[500] = "</a>";
    char *hashtagObtain = NULL;
    char *start, *end;

    //lets fill our counters with 0
    for(int intCount = 0; intCount < 100; intCount++) {
        hashtags[intCount].intCount = 0;
    }

    printf("Enter your file's name with the file extension\n");
    scanf("%s", strFileName);

    FILE* file;
    strcat(strDirectionFile, strFileName);


    file = fopen(strDirectionFile, "r");

    if(file == NULL) {
        printf("Could not open file %s",strFileName);
        return 1;
    }else  {
        printf("file open\n");
    }

   while(fgets(strWord, 100, file) != NULL) {

       //here we obtain the hashtag between the patterns and extract it
        if( start = strstr(strWord, strPatternbefore)) {
            start += strlen( strPatternbefore);
            if( end = strstr(start, strPatternAfter)) {
                hashtagObtain = (char * ) malloc(end - start +1);
                memcpy( hashtagObtain, start, end - start);
                hashtagObtain[end-start] = '\0';
            }
        }

        if( hashtagObtain) {
            for(int intCount = 0; intCount < 100 || intCount <= intIndex; intCount++) {
                if( strcmp(hashtags[intCount].strName, hashtagObtain) == 0 ) {
                    hashtags[intCount].intCount++;
                    break;
                } else if (strcmp(hashtags[intCount].strName, "") == 0 ) {
                    strcpy(hashtags[intCount].strName, hashtagObtain);
                    hashtags[intCount].intCount++;
                    intIndex++;
                    break;
                }
            }
            hashtagObtain = NULL;
        }
   }

   for(int intCount = 0; intCount < intIndex; intCount++) {
       printf("The hashtag #%s is used: %d times\n", hashtags[intCount].strName, hashtags[intCount].intCount);
   }

    free( hashtagObtain);
    fclose(file);

    return 0;
}