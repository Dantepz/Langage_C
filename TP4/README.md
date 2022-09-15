TP4 : Opérations bit-à-bit

Exercice 1 : Opérations logiques de base

    Indiquer ce qui est affiché par le programme suivant, avec les explications correspondantes :
        char a=16;
        a = a >> 4;
        printf("%d\n", a);
        a <<= 6;
        printf("%d\n", a);
        a <<= 1;
        printf("%d\n", a);

    Ecrire une fonction, basée sur l’utilisation de l’opérateur logique de décalage et le ET, permettant d’afficher sur une seule ligne la valeur binaire d’une variable. L’idée est d’afficher les bits du nombre un à un, de la gauche vers la droite. La récupération du bit à afficher peut être obtenue par un décalage et un masquage. 
    Rm : la solution la plus simple ne prend que 2 lignes, pour l’affichage proprement dit. La fonction devra avoir le prototype suivant :
        void printb(int a, int nb_bits);

    On souhaite réaliser un chenillard à 8 LEDs (séquence 00000001, 00000010, 00000100, 00001000, 00010000, 00100000, 01000000, 10000000, 00000001, …), dont l’état est donné par une variable de 8 bits. Compléter le programme suivant pour obtenir ce fonctionnement, en utilisant des opérations bit-à-bit. Pour l’affichage, on utilisera la fonction définie précédemment. 
    Rm : pour que les affichages se produisent toujours sur la même ligne, on peut utiliser le caractère \r en fin de ligne.
        char a=1;
        while(1)
        {
        ...
        getchar(); //attente d’appui sur une touche
        }

    Ecrire le programme ci-dessous et expliquer le résultat affiché.
        unsigned short int a=0xFF00, b;
        b = ~a;
        printf("b=%d\n", b);
    Réécrire la 2e ligne d’une manière différente : en utilisant l’opérateur OU-Exclusif (et une valeur numérique hexadécimale à 16 bits). Préciser quel est l’avantage de cette 2e méthode, par rapport à la 1ère.

Exercice 2 : Simulation de la programmation d’un microcontrôleur

    On considère un microcontrôleur doté d’un port d’entrée/sortie à 8 bits, programmable par l’intermédiaire de 2 variables (de type unsigned char) :
    # PIN : entrées du port
    # POUT : sorties du port
    On souhaite utiliser ce microcontrôleur pour gérer des lampes, à partir d’un interrupteur et d’un bouton-poussoir (interrupteur fermé/ouvert <-> resp. niveaux 0 et 1 ; bouton appuyé/relâché <-> resp. niveaux 0 et 1) :
        # Entrées :
            - Interrupteur connecté au bit (d’indice) 0 du port
            - Bouton-poussoir connecté au bit 1 du port
        # Sorties :
        - Lampe L1 connectée au bit 2 du port
        - Lampe L2 connectée au bit 3 du port
        - Lampe L3 connectée au bit 4 du port

    On souhaite avoir le fonctionnement suivant :
        # Lampes L1 et L2 commandées par l’interrupteur
        # Lampe L3 commandée par le bouton-poussoir (appui : allumage, appui suivant : extinction)
    Ecrire le programme permettant d’obtenir ce fonctionnement.
    Rm :
        - un programme comportant une partie du code-source est disponible sur ENT, et doit être complété
        - attention : le test de chacun des 3 cas d’utilisation devra être indépendant des 2 autres

Exercice 3 (bonus) Robot dans un labyrinthe

    Le programme "robot_labyrinthe.c" disponible sur ENT permet de simuler un robot devant sortir d’un labyrinthe, mais il est incomplet.
    Pour sortir d’un labyrinthe, une méthode consiste à longer les murs, toujours du même côté. On choisira ici de les longer par la droite. Cette méthode ne fonctionne néanmoins qu’avec les labyrinthes dit "parfaits" (c’est-à-dire sans murs isolés). 
    Compléter ce programme pour faire sortir le robot du labyrinthe.