#include <stdio.h>
#include <stdlib.h>

void printb(int a, int nb_bits) {
    for(int i = 0; i < nb_bits; i++)
        printf("%d", (((0x80 >> i)&a)== 0x80 >> i));
}

int main() {
    unsigned short int a=0xFF00, b;
    printf("hex = %x\nnew  = ", a);
    printb(a, 16);
}