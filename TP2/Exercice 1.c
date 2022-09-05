#include <stdio.h>


void main() {
    void calculTableau(); //Déclaration de la fonction
    int tab[16] = {0, -1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int arraySize = sizeof tab;
    int intSize = sizeof tab[0];
    int length = arraySize / intSize;

    calculTableau(tab, length); //Passage de la taille du tableau en paramètres pour savoir combien d'éléments il y a à parcourir
}

void calculTableau(int tab[], int length) {
    int min = tab[0], max, somme = 0, i;
    float moy;
    for (i = 0; i < length; i++) {
        printf("La valeur du tableau à l'indice %d est : %d\n", i, tab[i]);
        if(tab[i] > max)
            max = tab[i];
        if(tab[i] < min)
            min = tab[i];
        somme += tab[i];
    }
    moy = (float)somme / i;
    printf("Il y a %d valeurs dans le tableau.\n", length);
    printf("La valeur maximale est : %d\n", max);
    printf("La valeur minimale est %d\n", min);
    printf("La moyenne est de : %.2f\n", moy);
}