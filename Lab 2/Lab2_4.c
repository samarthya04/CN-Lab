#include <stdio.h>
#include <stdlib.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main(int argc, char *argv[]) {
    struct pkt number;
    int original_num, reconstructed_num;
    
    original_num = atoi(argv[1]);
    
    number.ch1 = (original_num >> 24) & 0xFF;
    number.ch2[0] = (original_num >> 16) & 0xFF;
    number.ch2[1] = (original_num >> 8) & 0xFF;
    number.ch3 = original_num & 0xFF;
    
    printf("Content of structure members:\n");
    printf("ch1: %d\n", (unsigned char)number.ch1);
    printf("ch2[0]: %d\n", (unsigned char)number.ch2[0]);
    printf("ch2[1]: %d\n", (unsigned char)number.ch2[1]);
    printf("ch3: %d\n", (unsigned char)number.ch3);
    
    reconstructed_num = ((unsigned char)number.ch1 << 24) |
                        ((unsigned char)number.ch2[0] << 16) |
                        ((unsigned char)number.ch2[1] << 8) |
                        (unsigned char)number.ch3;
    
    printf("Original number: %d\n", original_num);
    printf("Reconstructed number: %d\n", reconstructed_num);
    
    return 0;
}