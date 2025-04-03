#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    const char *receiver_ip = argv[1];
    int receiver_port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in receiver_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&receiver_addr, 0, sizeof(receiver_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(receiver_port);
    receiver_addr.sin_addr.s_addr = inet_addr(receiver_ip);

    while (1)
    {
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM,
               (const struct sockaddr *)&receiver_addr, sizeof(receiver_addr));

        if (strcmp(buffer, "exit") == 0)
            break;

        int n;
        socklen_t len = sizeof(receiver_addr);
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL,
                     (struct sockaddr *)&receiver_addr, &len);
        buffer[n] = '\0';
        printf("Receiver: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0)
            break;
    }

    close(sockfd);
    return 0;
}
