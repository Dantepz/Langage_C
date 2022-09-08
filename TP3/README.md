TP3 : Pointeurs


Exercice 1 : Compréhension des pointeurs

    On considère les lignes de code suivantes :
    int A[] = {2, 27, 3, 13, 28, 17, 31, 9, 20, 6};
    int x;
    int *P;
    P=A;
    Compléter le tableau ci-dessous, en indiquant ce que donne l’affichage de la variable xm
    (de type int) par la fonction printf, après exécution de chacune des instructions de la
    colonne de gauche (de haut en bas). Compléter par les explications utiles dans le tableau, puis
    conclure sur les opérations arithétiques portant sur des variables ou sur des pointeurs. 
        x=*P
        x=*(P+3)
        x=*P+1
        x=P
        x=P+1
        x=A[4]-2
        x=&A[4]-2
        x=A+4
        x=&A[9]-P
        x=P+(*P-1)


Exercice 2 : Pointeurs et chaînes de caractères

    Un palindrome est un texte ou un mot dont l'ordre des lettres reste le même qu'on le lise de gauche à droite ou de droite à gauche. Exemple : «Engage le jeu, que je le gagne».
    Pour détecter un palindrome, le principe peut être basé sur deux pointeurs, le 1er parcourant la chaîne dans le sens direct et le 2e dans le sens inverse. On peut comparer le
    contenu de ces 2 pointeurs entre eux à chaque itération d’une boucle, et dès qu’on détecte une différence, on peut conclure qu’il ne s’agit pas d’un palindrome (et arrêter le traitement).
    On souhaite développer une fonction retournant la valeur 1 si une chaîne contient un palindrome, 0 sinon. Cette fonction devra être basée sur l’utilisation de pointeurs. Son prototype devra être :
        int mot_palindrome(char *chaine);
    a) Développer cette fonction et un petit programme principal permettant de la tester. Pour simplifier le développement, on se limitera dans un premier temps aux cas où la chaîne de caractères est composée d’un seul mot.
    b) Adapter la fonction pour gérer les cas où la chaîne de caractères contient des espaces et des apostrophes.

    Informations utiles :
        - Pour sortir prématurément d’une boucle, on peut utiliser l’instruction break 2
        - Pour saisir une chaîne de caractères au clavier, on peut utiliser la fonction gets()définie dans le fchier d’entête string.h
        - Pour connaître la longueur d’une chaîne de caractères, on peut utiliser la fonction strlen() (également de string.h)
        - Pour passer directement à l’itération suivante d’une boucle, on peut utiliser l’instruction continue


Exercice 3 : Pointeurs et tableaux

    a) Écrire un programme qui :
        - saisisse au clavier les n éléments d’un tableau de type int ;
        - inverse l’ordre de ces éléments (le 1er devient le dernier, etc), sans utiliser un 2e tableau.
        La saisie et la réorganisation des éléments du tableau devront utiliser des pointeurs.
        Rm : le tableau devra être dimensionné dans le code source à une taille maximale N (ex. 10), et le nombre d’éléments choisi n devra être ≤ N.
    b) Ecrire un programme qui lise au clavier un entier x à retirer d’un tableau, c’est-à-dire que toutes les occurrences de x devront être éliminées, en "tassant" (=déplaçant vers la gauche) les éléments restants. Le programme devra utiliser des pointeurs et ne pas utiliser un 2e tableau.
    L’opération de "tassement" pourra être basée sur 2 boucles while imbriquées :
        - la 1ère pour le parcours de tous les éléments du tableau à traiter
        - la 2e pour le décalage du reste du tableau quand l’élément à enlever x est détecté.
    Remarque : pour simplifier la conception du programme, on pourra procéder en 2 étapes :
        - version 1 qui ne traite que les cas où il n’y a pas deux éléments x consécutifs dans le tableau
        - version 2 pour le cas général.
