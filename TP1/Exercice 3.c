#include <stdio.h>
#include <stdbool.h>

#define Oridnateur = 0;
#define Humain = 1;

void main() {
    int NbrAllumettes, coup, joueur;

    printf("Saisir le nombre d'allumettes : ");
    scanf("%d", &NbrAllumettes);
    printf("Saisir qui commence (1 : Humain & 0 : Ordinateur) : ");
    scanf("%d", &joueur);

    while(NbrAllumettes > 1){
        if (joueur) { //Si le joueur commence
            printf("Saisir le nombre d'allumettes à retier : ");
            scanf("%d", &coup);
            NbrAllumettes -= coup;
            joueur = 0;
            printf("Il reste %d allumettes.\n", NbrAllumettes);
        } else { //Si l'ordi commence
            coup = (NbrAllumettes -1)%4;
            if(coup == 0) {
                coup = 1;
            }
            NbrAllumettes -= coup;
            joueur = 1;
            printf("Il y a %d allumettes restantes et je prend %d\n", NbrAllumettes, coup);
        }
    }
    if(joueur)
        printf("Le joueur à gagné !");
    else 
        printf("L'ordinateur à gangé !");
}
