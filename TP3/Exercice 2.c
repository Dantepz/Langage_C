#include <stdio.h>
#include <string.h>

int mot_palindrome(char *chaine) {
    int length = strlen(chaine), indiceDebut = 0, indiceFin = 0;
    char *pDebut, *pFin;

    pFin = *(chaine + length -1);
    pDebut = *chaine;

    while (pDebut != '\0') {
        if(pDebut == '\'' || pDebut == ' ') {
            indiceDebut += 1;
            pDebut = *(chaine + indiceDebut);
        }
        if(pFin == '\'' || pFin == ' ') {
            indiceFin += 1;
            pFin = *(chaine + length - 1 - indiceFin);
        }
        if(pDebut != pFin) {
            printf("Ce n'est pas un palindrome\n");
            return 0;
        }

        indiceDebut += 1;
        indiceFin +=1;
        pDebut = *(chaine + indiceDebut);
        pFin = *(chaine + length - 1 - indiceFin);
    }
    printf("C'est un palindrome\n");
    return 1;
}

void main() {
    char chaine[20] = {"la mariee ira mal"};
    int palindrome = mot_palindrome(chaine);
}

