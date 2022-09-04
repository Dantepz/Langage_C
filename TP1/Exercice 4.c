#include<stdio.h>

void QuestionA();
void QuestionB();
void QuestionC();
void QuestionD();

void main() {
    //Décommenter la ligne correspondante à la ligne souhaitée.
    // QuestionA();
    // QuestionB();
    // QuestionC();
    // QuestionD();
}

//Question a)
void QuestionA() {
    int nombre;

    while (1)
    {
        printf("Entrez un nombre entier :");
        scanf("%d", &nombre);

        for (int i = 1; i <= nombre ; i++) {
            if (nombre % i == 0) {
                printf("%d\n", i);
            }
        }
    }
    
}

//Question b)
void QuestionB() {
    int nombre, nombrePremier;
    nombrePremier = 0;

    while (1)
    {
        printf("Entrez un nombre entier :");
        scanf("%d", &nombre);

        for (int i = 1; i <= nombre ; i++) {
            if (nombre % i == 0) {
                printf("%d\n", i);
                nombrePremier++;
            }
        }
        if(nombrePremier == 2) {
            printf("Ce nombre est premier.\n");
        }
    }
}

//Question c)
void QuestionC() {
    int nombre, nombrePremier, somme;
    nombrePremier = 0;
    somme = 0;

    while (1)
    {
        printf("Entrez un nombre entier :");
        scanf("%d", &nombre);

        for (int i = 1; i <= nombre ; i++) {
            if (nombre % i == 0) {
                printf("%d\n", i);
                nombrePremier++;
                if(nombre != i) {
                    somme += i;
                }
            }
        }
        if(nombrePremier == 2) {
            printf("Ce nombre est premier.\n");
        }
        if(nombre == somme) {
            printf("Ce nombre est parfait.\n");
        }
    }
    
}

//Question d)
void QuestionD()
{
    int nombre, nbrPremier, nbrPremierTotal, somme;
    nbrPremier = 0;
    nbrPremierTotal = 0;
    nombre = 0;
    somme = 0;

    while(nbrPremier < 40000){
        for (int i = 1; i<= nombre; i++) {
            if (nombre % i == 0){
                nbrPremier++;
            }
        }
        if(nbrPremier<=2){
            nbrPremierTotal++;
            printf("%d\n",nombre);
            printf("%d\n",nbrPremierTotal);
        }
    }
    printf("%d\n",nombre);
}