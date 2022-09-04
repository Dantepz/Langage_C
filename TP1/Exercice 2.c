#include<stdio.h>
#include<stdbool.h>

void main() {
    int annee;
    bool isAnneeBissextile;

    while(1) {
        printf("Saisir une annee : ");
        scanf("%d", &annee);

        if(annee >= 0) {
            if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
                isAnneeBissextile = true;
            else
                isAnneeBissextile = false;
        } else {
            continue;
        }
        printf("%s\n", isAnneeBissextile ? "L'annee est bissextile" : "L'annee n'est pas bissextile");
    }
}