#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]){
    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("Before Swapping\n");
    printf("Num 1 = %d\n", a);
    printf("Num 2 = %d\n", b);
    swap(&a, &b);
    printf("After Swapping\n");
    printf("Num 1 = %d\n", a);
    printf("Num 2 = %d\n", b);
    return 0;
}