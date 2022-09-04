#include<stdio.h>
#include<stdbool.h>

void main() {
    int annee;
    bool isAnneeBissextile;

    while(1) {
        printf("Saisir une année : ");
        scanf("%d", &annee);

        if(annee >= 0) {
            if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
                isAnneeBissextile = true;
            else
                isAnneeBissextile = false;
        } else {
            printf("L'année saisie est négative. Le traitement est impossible.\nVeuillez saisir une année positive.\n");
            continue;
        }
        printf("%s\n", isAnneeBissextile ? "L'année est bissextile" : "L'année n'est pas bissextile");
    }
}