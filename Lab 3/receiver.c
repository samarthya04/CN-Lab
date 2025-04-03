#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    const char *sender_ip = argv[1];
    int receiver_port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in sender_addr, receiver_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&receiver_addr, 0, sizeof(receiver_addr));
    memset(&sender_addr, 0, sizeof(sender_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(receiver_port);
    receiver_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (const struct sockaddr *)&receiver_addr, sizeof(receiver_addr));

    socklen_t len = sizeof(sender_addr);

    while (1)
    {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL,
                         (struct sockaddr *)&sender_addr, &len);
        buffer[n] = '\0';
        printf("Sender: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0)
            break;

        printf("Enter response: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM,
               (const struct sockaddr *)&sender_addr, len);

        if (strcmp(buffer, "exit") == 0)
            break;
    }

    close(sockfd);
    return 0;
}
