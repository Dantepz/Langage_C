#include <stdio.h>
#include <stdbool.h>

#define Oridnateur = 0;
#define Humain = 1;
void main()
{

    int NbrAllumettes, coup, joueur;

    printf("Saisir le nombre d'allumettes : ");
    scanf("%d", &NbrAllumettes);
    printf("Saisir qui commence (1 : Humain & 0 : Ordinateur) : ");
    scanf("%d", &joueur);

    while(NbrAllumettes > 1){
            if (joueur = 0) { //Si l'ordi commence
                    coup = (NbrAllumettes -1)%4;
                    if(coup == 0) {
                            coup = 1;
                            printf("Il y a %d allumettes restantes et je prend %d\n", NbrAllumettes, coup);
                        } else {
                        printf("Il y a %d allumettes restantes. Votre coup :\n", NbrAllumettes);
                        scanf("%d", &coup);
                        if(coup > 3 || coup < 1) {
                            continue;
                        }
                    }
                    NbrAllumettes -= coup;
                    joueur != joueur;
            } else { //Si le joueur commence

            }
    }
}
