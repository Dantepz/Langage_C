#include <stdio.h>
#include <stdlib.h>

void main() {
    int A[] = {2, 27, 3, 13, 28, 17, 31, 9, 20, 6};
    int x;
    int *P;
    P=A;

    //x = *P;
    //x = *(P+3);
    //x = *P + 1;
    //x = P;
    //x = P + 1;
    //x = A[4] - 2;
    //x = &A[4] - 2;
    //x = A + 4;
    //x = &A[9] – P;
    x = P+(*P - 1);

    printf("%d", x);
}
