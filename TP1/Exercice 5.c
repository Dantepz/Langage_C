#include <stdio.h>

void main() {
    int n1, n2, min, max;
    float moyenne;
    max = 0;

    do {
        printf("Donner le nombre de valeurs : ");
        scanf("%d", &n1);
    } while(n1 < 0);

    for (int i = 0; i < n1; i++) {
        do
        {
            printf("Donner le nombre de valeurs pour le %d nombre : ", i+1);
            scanf("%d", &n2);
        } while (n2 < 0);
        
        if(i == 0) {
            min = n2;
            moyenne = n2;
        }

        if (n2 > max) 
            max = n2;
        if (n2 < min)
            min = n2;

        moyenne = ((n1 - 1) * moyenne + n2)/n1;

        printf("La valeur minimale est actuellement %d\n", min);
        printf("La valeur maximale est actuellement %d\n", max);
        printf("La valeur moyenne est actuellement %d\n", moyenne);
    }
}