#include<stdio.h>

void main()
{
    int nombre, nbrPremier, nbrPremierTotal, somme;
    nbrPremier = 0;
    nbrPremierTotal = 0;
    nombre = 1;
    somme = 0;

    while(nbrPremier < 40000){
        for (int i = 1; i<= nombre; i++) {
            if (nombre % i == 0){
                nbrPremier++;
            }
        }
        if(nbrPremier<=2){
            nbrPremierTotal++;
            printf("%d\n",nombre);
            printf("%d\n",nbrPremierTotal);
        }
    }
    printf("%d\n",nombre);
}