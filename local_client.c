#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
    int sockfd, n;
    struct sockaddr_un serv_addr;
    char buffer[256];

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

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Send message to server
    strcpy(buffer, "Hello, server!");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read server response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}