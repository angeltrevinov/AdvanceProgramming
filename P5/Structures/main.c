#include <stdio.h>
#include <string.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 22/08/2019
 *
 * Program that saves the information of an agent in a
 *      structure
 * */

//==========================================================
struct Agent {
    //Save strings as arrays with max length set to 200
    //      length of a name
    char strFirstName[200];
    char strLastName[200];
    int intAge;
    char strGender[200];
    char strMission[200]; //3 letter code and 9 digits
};

//----------------------------------------------------------
int main() {
    struct Agent agent;
    //Just a validator to know if to accept mission, no
    //      booleans in C
    char charValidator = 'f';
    printf("Enter the Agent's first name\n");
    scanf(" %s", agent.strFirstName);
    printf("Enter the Agent's last name\n");
    scanf(" %s", agent.strLastName);
    printf("Enter the Agent's Age\n");
    scanf("%d", &agent.intAge);
    printf("Enter the Agent's gender\n");
    scanf("%s", agent.strGender);

    //Validate mission input
    do {
        printf("Enter the mission's Id, remember 3 "
               "letters at beginning and 9 digits\n");
        scanf("%s", agent.strMission);

        if(
                //The mission length is 12
                strlen(agent.strMission) == 12
                ){
            int intPos = 0;

            for(
                    //check if the first three characters
                    //      are letters
                    ; intPos < 3 ; intPos++
                    ) {
                if(
                        (agent.strMission[intPos] >= 'a' &&
                        agent.strMission[intPos] <= 'z') ||
                        (agent.strMission[intPos] >= 'A' &&
                        agent.strMission[intPos] <= 'Z')) {
                    charValidator = 't';
                }
            }

            for (
                    //Check if the other characters are
                    //      numbers
                    ; intPos < 12 && charValidator == 't'; intPos++
                    ) {
                if(
                        //If its not a number, break
                        !(agent.strMission[intPos] >= '0' &&
                        agent.strMission[intPos] <= '9')
                        ) {
                    charValidator = 'f';
                }
            }
        }

    } while(
            charValidator == 'f'
            );

    printf("Name; %s %s \n"
           "Age: %d \n"
           "Gender: %s \n"
           "Mission: %s",
           agent.strFirstName,
           agent.strLastName,
           agent.intAge,
           agent.strGender,
           agent.strMission);

    return 0;
}