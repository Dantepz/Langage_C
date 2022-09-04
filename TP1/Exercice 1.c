#include<stdio.h>

void main() {
    int a, somme;

    while(1) {
        printf("Saisissez une valeur de a entre 0 et 10 : ");
        scanf("%d", &a);
        printf("Vous avez saisi la valeur : %d\n", a);

        if(a <0 || a > 10) {
            continue;
        }
        for(int i = 1; i <= a; i++) {
            somme += i;
        }
        printf("La somme des %d premiers entiers est %d\n", a, somme);
        somme = 0;
    }
}