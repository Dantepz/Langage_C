#include <stdio.h>

void main() {
    void insertion_element(); //Déclaration de la fonction
    int tab[] = {6, 0, 5, 3};
    for(int i = 0; i < 4; i++) {
        insertion_element(tab, tab[i], i); // Passage par adresse du tableau
    }
    for(int j = 0; j < 4 ; j++) {
        printf("%d ", tab[j]);
    }
}

void insertion_element(int tab[], int elem, int i_elem) {
    int tmp, i;
    for(i = i_elem; i >= 0; i--) {
        if(elem < tab[i]) {
            tmp = tab[i];
            tab[i] = elem;
            tab[i+1] = tmp;
        } 
    }
}