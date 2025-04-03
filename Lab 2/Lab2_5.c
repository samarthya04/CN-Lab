#include <stdio.h>
#include <stdlib.h>

int is_little_endian() {
    int x = 1;
    return (*(char *)&x == 1);
}

void print_bytes(int x) {
    unsigned char *p = (unsigned char*)&x;
    for (int i = 0; i < sizeof(int); i++) {
        printf("Byte %d: %d\n", i, p[i]);
    }
}

int convert_endianness(int x) {
    return ((x >> 24) & 0xFF) | 
           ((x >> 8) & 0xFF00) | 
           ((x << 8) & 0xFF0000) | 
           ((x << 24) & 0xFF000000);
}

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);

    if (is_little_endian()) {
        printf("This machine is Little Endian.\n");
    } else {
        printf("This machine is Big Endian.\n");
    }

    printf("\nOriginal number: %d\n", num);
    printf("Bytes of the original number:\n");
    print_bytes(num);

    int converted = convert_endianness(num);

    printf("\nNumber after endianness conversion: %d\n", converted);
    printf("Bytes of the converted number:\n");
    print_bytes(converted);

    return 0;
}