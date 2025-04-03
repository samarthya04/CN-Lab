#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);

    unsigned char byte3 = (num >> 24) & 0xFF;
    unsigned char byte2 = (num >> 16) & 0xFF;
    unsigned char byte1 = (num >> 8) & 0xFF;
    unsigned char byte0 = num & 0xFF;

    printf("Byte 0: %d\n", byte0);
    printf("Byte 1: %d\n", byte1);
    printf("Byte 2: %d\n", byte2);
    printf("Byte 3: %d\n", byte3);

    return 0;
}
