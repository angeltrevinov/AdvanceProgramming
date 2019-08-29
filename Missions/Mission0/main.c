#include <stdio.h>

/*
 * Author: Angel Treviño
 * Matricula: A01336559
 * Fecha: 29/08/19
 *
 * A program that lets you add agents and delete them, does
 *      not keep agents in memory, data gets deleted if you
 *      stop the program.
 * */

//==========================================================
struct Agent {
    //Save strings as arrays with max length set to 200
    //      length of a name
    char strFirstName[200];
    char strLastName[200];
    char strActives[200]; //4 letters and 9 digits
    int intAge;
    char strMission[200]; //3 letter code and 9 digits
};

//----------------------------------------------------------
char verifyMission() {

}

//----------------------------------------------------------
char verifyActives(char *strActive) {
    return 't';
}

//----------------------------------------------------------
void printAgents() {

}

//----------------------------------------------------------
struct Agent addAgent(
        //Method that receives the user input for the agent
        //      to be added and returns it as an agent
) {
    struct Agent agent;
    char cValidator = 'f';
    printf("First name of your agent:\n");
    scanf("%s", agent.strFirstName);
    printf("Last name of your agen:\n");
    scanf("%s", agent.strLastName);
    do {
        printf("Enter the agents active\n"
               "**Remember you need 4 letters and 9 digits**\n");
        scanf("%s", agent.strActives);
        cValidator = verifyActives(agent.strActives);
    }while(cValidator == 'f');
}

//----------------------------------------------------------
void deleteAgent() {
}


//----------------------------------------------------------
int main() {

    int intChoice;
    do {
        printf("***************************************\n");
        printf("WELCOME TO THE MENU \n"
               "CHOOSE WHATEVER YOU LIKE\n");
        printf("1. Add Agent\n");
        printf("2. Delete an Agent\n");
        printf("3. Print Agents\n");
        printf("4. Exit Program\n");
        printf("***************************************\n");
        scanf("%d", &intChoice);

        if(intChoice == 1) {
            addAgent();
        } else if(intChoice == 2) {
            deleteAgent();
        } else if(intChoice == 3) {
            printAgents();
        }

    } while(intChoice != 4);

    return 0;
}