#include <stdio.h>

void main() {
    void permute(); //Déclaration de la fonction
    int tab[] = {8, 5};
    int x = 0;
    int y = 1;
    permute(tab, x, y);
}

void permute(int tab[], int x, int y) {
    int tmp = tab[y];
    if(tab[x] > tab[y]) {
        tab[1] = tab[x];
        tab[0] = tmp;
    }
}
test