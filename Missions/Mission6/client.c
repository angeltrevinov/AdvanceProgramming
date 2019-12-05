#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>
#include <arpa/inet.h>

#define MAX_EVENTS 1024
#define LEN_NAME 1024
#define EVENT_SIZE ( sizeof (struct inotify_event))
#define BUF_LEN (MAX_EVENTS * (EVENT_SIZE + LEN_NAME))

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Mission 6 Client
 *      The client program that monitors a folder and sends
 *      it to the server to store
 * */

int PORT_NUMBER;

//================== SERVER SETUP ==========================
void sendFile(char *nameOfFile) {
    int sfd =0, n=0, b;
    char rbuff[1024];
    char sendbuffer[100];

    struct sockaddr_in serv_addr;

    memset(rbuff, '0', sizeof(rbuff));
    sfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_NUMBER);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    b=connect(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (b==-1) {
        perror("Connect");
        exit(1);
    }

    FILE *fp = fopen("Test/test.txt", "rb");
    if(fp == NULL){
        perror("File");
        exit(1);
    }

    while( (b = fread(sendbuffer, 1, sizeof(sendbuffer), fp))>0 ){
        send(sfd, sendbuffer, b, 0);
    }
    close(sfd);
    fclose(fp);
}
//==========================================================

//================== FOLDER MONITORING =====================
//==========================================================

/*
 * changeDetection
 *
 * Method that is in charge of detecting folder changes and
 *      call the server to update
 * */
//----------------------------------------------------------
void changeDetection(int fd) {
    char buffer[BUF_LEN];
    int length, i = 0, entered = 0;

    //read to determine the event change happening on our
    //  folder. Actually reads blocks until the change occurs
    length = read(fd, buffer,BUF_LEN);
    //Error detection
    if(length < 0) {
        perror("Error on read");
    }

    //read the return the list of change events. Read one by
    //  one and process it accordingly
    while(i < length) {
        struct inotify_event *event =
                (struct inotify_event * ) &buffer[i];

        if(event->len) {
            sendFile(event->name);
            //On Create Event
            if ( event -> mask &  IN_CREATE) {
                if( event -> mask & IN_ISDIR) {
                    printf("The folder %s was created\n", event->name);
                } else {
                    printf("The file %s was modified\n", event->name);
                }
            }
            //On Modify Event
            if(event->mask & IN_MODIFY) {
                if(event->mask & IN_ISDIR) {
                    printf("The folder %s was modified\n", event->name);
                } else {
                    printf("The file %s was modified\n", event->name);
                }
            }
            //On Delete Event
            if(event-> mask & IN_DELETE) {
                if(event-> mask & IN_ISDIR) {
                    printf("The folder %s was deleted\n", event->name);
                } else {
                    printf("The file %s was deleted\n", event->name);
                }
            }
            i+= EVENT_SIZE + event->len;
        }
    }
}

/*
 * onFolderModified
 *
 * Method that is in charge of creating the notify and call
 *      the change detection of the notify
 * */
//----------------------------------------------------------
void onFolderModified(char *strFolderName) {

    int fd, wd;
    fd = inotify_init();

    //Error detection
    if (fd < 0) {
        perror("Error on inotify_init");
    }

    wd = inotify_add_watch(
            //Our notify
            fd,
            //Our Folder
            strFolderName,
            //The events to check for our folder
            IN_CREATE | IN_MODIFY | IN_DELETE
          );

    if(wd == -1) {
        printf("There was a problem monitoring %s \n", strFolderName);
        return;
    } else {
        printf("Starting to monitoring %s \n", strFolderName);
    }

    while (1) {
        changeDetection(fd);
    }

    inotify_rm_watch(fd, wd);
    close(fd);
}
//==========================================================

//----------------------------------------------------------
int main(int argc, char **argv) {

    if(argc == 1) {
        printf("ERROR: missing a parameter\n");
        return 1;
    } else {
        PORT_NUMBER = atoi(argv[2]);
        onFolderModified(argv[1]);
    }

    return 0;
}