#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_un serv_addr, cli_addr;
    int n;

    // Create socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, "/tmp/socket");

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    // Start listening for clients
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept connection from client
    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        // If connection is established then start communicating
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Here is the message: %s\n", buffer);

        // Write a response to the client
        n = write(newsockfd, "Thank you for connecting", 24);
        if (n < 0)
        {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(newsockfd);
    }
    close(sockfd);
    unlink("/tmp/socket"); // Remove the socket file
    return 0;
}