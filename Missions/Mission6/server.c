#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>


/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Mission 6 Client
 *      The server program that stores the folders of the
 *      clients
 * */

//----------------------------------------------------------
int main(int argc, char **argv) {

    if(argc == 1) {
        printf("ERROR: no port was provided\n");
        exit(1);
    }

    int fd =0, confd = 0,b,tot;
    struct sockaddr_in serv_addr;

    char buff[1025];
    int num, port;
    port = atoi(argv[1]);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket created\n");

    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(buff, '0', sizeof(buff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    bind(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(fd, 10);

    while(1){
        confd = accept(fd, (struct sockaddr*)NULL, NULL);
        if (confd==-1) {
            perror("Accept");
            continue;
        }
        FILE* fp = fopen( "StoredServer/result.txt", "wb");
        tot=0;
        if(fp != NULL){
            while( (b = recv(confd, buff, 1024,0))> 0 ) {
                tot+=b;
                fwrite(buff, 1, b, fp);
            }

            printf("Received byte: %d\n",tot);
            if (b<0)
                perror("Receiving");

            fclose(fp);
        } else {
            perror("File");
        }
        close(confd);
    }

    return 0;
}