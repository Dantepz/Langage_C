#include <stdio.h>
#include <time.h>

int main() {
    int tab[20];
    int TAILLE = 100;
    int *p1;
    int *p2;
    int nb = 0, nb1, nb2;
    int temp = 0;
    int supp_nb;

    while(TAILLE>20)
    {
        printf("Saisir la dimension du tableau (max 20) : ");
        scanf("%d", &TAILLE);
    }
    printf("\nVeuillez saisir les valeurs du tableau : ");
    for(nb = 0; nb < TAILLE; nb++)
    {
        scanf("%d", &temp);
        *(tab + nb) = temp;
    }
    nb = 0;
    while(nb < TAILLE / 2) {
            nb1 = *(tab + nb);
            nb2 = *(tab + TAILLE - 1 - nb);
            *(tab + nb) = nb2;
            *(tab + TAILLE - 1 - nb) = nb1;
            nb++;
    }

    printf("\nLe tableau est : |");
    for(nb = 0; nb < TAILLE; nb++)
    {
        printf("%d|", *(tab +nb));
    }

    printf("\nSaisissez le nombre a retirer");
    scanf("%d",&supp_nb);

    int i = 0;
    int nbX = 0;

    while(i<TAILLE){
        if(tab[i] == supp_nb){
            nbX++;
            int i2 = i;
            while(i2<TAILLE){
                p1 = *(tab+i2+1);
                tab[i2] = p1;
                i2++;
            }
        }
        p1 = *(tab+i);
        if(p1 != supp_nb){i++;}
    }

    for(int u=0; u<TAILLE-nbX; u++){
        printf("|%d|", tab[u]);
    }
}
