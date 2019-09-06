#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
 * Author: Angel Treviño
 * Matricula: A01336559
 * Fecha: 29/08/19
 *
 * A program that lets you add agents and delete them, does
 *      not keep agents in memory, data gets deleted if you
 *      stop the program. needs a password to see data or do
 *      actions
 *
 *      the password is: MISSION1
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

//==========================================================
struct Node {
    struct Agent agent;
    struct Node* next;
};

//----------------------------------------------------------
bool verifyMission(
        //Method that verifies if the mission is written
        //      correctly, with 3 letters and 9 digits
        //Receives the string with the mission info
        char *strMission
) {

    if( strlen(strMission) != 12) {
        return false;
    }

    int intPos = 0;

    for(; intPos < 3; intPos++) {
        if(!(
                (strMission[intPos] >= 'a' &&
                 strMission[intPos] <= 'z') ||
                (strMission[intPos] >= 'A' &&
                 strMission[intPos] <= 'Z')
        )){
            return false;
        }
    }

    for (; intPos < 12; intPos++) {
        if(
            //If its not a number, break
                !(strMission[intPos] >= '0' &&
                  strMission[intPos] <= '9')) {
            return false;
        }
    }

    return true;

}

//----------------------------------------------------------
bool verifyActives(
        //Method that validates if the Active's input is
        //      written correctly, with 4 letters and 9
        //      digits
        //Receives the string with the active info
        char *strActive
) {
    if(
        //If the length is not right
            strlen(strActive) !=  13
            ) {
        return  false;
    }

    int intPos = 0;

    for(
        //check if the first four characters are letters
            ; intPos < 4; intPos++
            ) {
        if(!(
                (strActive[intPos] >= 'a' &&
                 strActive[intPos] <= 'z') ||
                (strActive[intPos] >= 'A' &&
                 strActive[intPos] <= 'Z')
        )) {
            return false;
        }
    }

    for(
        //Check if the other characters are numbers
            ; intPos < 13; intPos++) {

        if(
            //If its not a number, break
                !(strActive[intPos] >= '0' &&
                  strActive[intPos] <= '9')) {
            return false;
        }
    }

    return true;

}

//----------------------------------------------------------
void pushAgent(
        //Method that adds the agent to the linked list at
        //      the beginning
        struct Node** head,
        struct Agent agentToAdd
) {

    struct Node* newAgent = (struct Node*)malloc(sizeof(struct Node));
    newAgent -> agent = agentToAdd;
    newAgent -> next = (*head);
    (*head) = newAgent;
}

//----------------------------------------------------------
void deleteAgent(
        //Method that deletes an agent based on the mission
        struct Node **head
) {
    char strMission[200];
    do {
        printf("Enter the agent's mission you want to delete\n");
        scanf("%s", strMission);
    }while (!verifyMission(strMission));

    struct Node* agentToDelete = *head, *prev;

    if(
        //If the agent needs to be deleted
            agentToDelete != NULL
            && strcmp(agentToDelete -> agent.strMission, strMission) == 0
            ) {

        *head = agentToDelete -> next; // change the head
        free(agentToDelete); //delete the node
        return;
    }

    while(
            agentToDelete != NULL &&
            strcmp(agentToDelete -> agent.strMission, strMission) != 0
            ) {
        prev = agentToDelete;
        agentToDelete = agentToDelete -> next;
    }

    if(agentToDelete == NULL) {
        printf("The mission: %s couldn't be find\n", strMission);
        return;
    }

    prev -> next = agentToDelete -> next;
    free(agentToDelete);
}

//----------------------------------------------------------
void printAgents(struct Node *node, char strPassword[200]) {
    printf("%s \n", strPassword);
    struct Agent agent;
    while(node != NULL) {
        agent = node ->agent;

        if(strcmp(strPassword, "MISSION1")  != 0) {
            
        }

        printf("Name: %s %s \n"
               "Actives: %s \n"
               "Age: %d \n"
               "Mission: %s \n",
               agent.strFirstName,
               agent.strLastName,
               agent.strActives,
               agent.intAge,
               agent.strMission);
        printf("*********\n \n");
        node = node -> next;
    }

}

//----------------------------------------------------------
struct Agent createAgent(
        //Method that receives the user input for the agent
        //      to be added and returns it as an agent
) {
    struct Agent agent;
    printf("First name of your agent:\n");
    scanf("%s", agent.strFirstName);
    printf("Last name of your agen:\n");
    scanf("%s", agent.strLastName);

    do {
        printf("Enter the agent's active\n"
               "**Remember you need 4 letters and 9 digits**\n");
        scanf("%s", agent.strActives);
    }while(!verifyActives(agent.strActives));

    printf("Enter the agent's age\n");
    scanf("%d", &agent.intAge);

    do {
        printf("Enter the agent's mission\n"
               "**Remember you need 3 letters and 9 digits\n");
        scanf("%s", agent.strMission);
    } while (!verifyMission(agent.strMission));

    return agent;
}

//----------------------------------------------------------
void findAgent(struct Node* node) {

    char strAgentToFind[200];
    printf("Enter your agent's last name or their active");

}

//----------------------------------------------------------
int main(
        //When running, include the password as argument
        int argc, char const *argv[]
        ) {

    int intChoice;
    char password[200];

    strcpy(password, argv[1]);

    struct Node* AgentsHead = NULL;
    do {
        printf("***************************************\n");
        printf("WELCOME TO THE MENU \n"
               "CHOOSE WHATEVER YOU LIKE\n");
        printf("1. Add Agent\n");
        printf("2. Find an Agent\n");
        printf("3. Print Agents\n");
        printf("4. Exit Program **YOUR DATA WILL BE LOST**\n");
        printf("***************************************\n");
        scanf("%d", &intChoice);

        if(intChoice == 1 && strcmp(password, "MISSION1")  == 0) {
            struct Agent agent;
            agent = createAgent();
            pushAgent(&AgentsHead, agent);
        } else if(intChoice == 2 && strcmp(password, "MISSION1")  == 0) {
            findAgent(AgentsHead);
        } else if(intChoice == 3) {
            printAgents(AgentsHead, password);
        } else if ( strcmp(password, "MISSION1")  != 0) {
            printf("*** ERROR YOU CANNOT PERFOM THIS ACTION ***\n");
        }

    } while(intChoice != 4);

    return 0;
}