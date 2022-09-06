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

void insertion_element(int tab[], int element, int i_element) {
    int tmp, i;
    for(i = i_element; i >= 0; i--) {
        if(element < tab[i]) {
            tmp = tab[i];
            tab[i] = element;
            tab[i+1] = tmp;
        } 
    }
}