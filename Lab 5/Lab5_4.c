#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

float calculate_gross_salary(float basic_salary) {
    float hra = 0.15 * basic_salary;
    float da = 0.50 * basic_salary;
    return basic_salary + hra + da;
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    float basic_salary, gross_salary;
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 1);

    addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    
    recv(client_socket, &basic_salary, sizeof(basic_salary), 0);
    gross_salary = calculate_gross_salary(basic_salary);
    send(client_socket, &gross_salary, sizeof(gross_salary), 0);
    
    close(client_socket);
    close(server_socket);

    return 0;
}
