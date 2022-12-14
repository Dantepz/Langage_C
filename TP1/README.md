TP1 : Les bases


Exercice 1 : Le jeu des 7 erreurs

    Le programme ci-dessous comporte 7 erreurs, qui posent un problème soit à la compilation soit à l’exécution.
    L’écrire ou le recopier dans Code::Blocks. Essayer de le compiler et indiquer quelles sont ces erreurs et leur nature (erreur à la compilation ou erreur à l’exécution).
    Corriger ces erreurs pour que le programme fonctionne.

#include<stdio.h>
main()
{
    int a, somme;
    while(1)
    {
        printf("saisissez une valeur de a entre 0 et 10 : ");
        scanf("%d", a);
        printf("vous avez saisi la valeur : %f\n", a);
        if(a<0 OR a>10);
            continue;
        for(i=1 , i<=a , i++)
            somme = somme + i;
        printf("La somme des %d premiers nombres entiers est %d\n", a, somme);
    }
}


Exercice 2 : Année bissextile ou non ?

    L’année 2000 était une année bissextile, mais 1900 ne l’était pas et 2100 ne le sera pas non plus. Pourquoi ?
    Le temps que met la terre pour tourner une fois autour du soleil est de 365,2422 jours. Le calendrier grégorien (l’actuel) est basé sur une durée de 365,2425 jours, qu’on peut mettre sous la forme :
    365,2425=365+  1/4-  1/100+  1/400
    Pour compenser la dérive qu’impliqueraient des années de 365 jours, on introduit donc un jour supplémentaire tous les 4 ans (le 29 février), sauf les années multiples de 100, mais à l’exception des années multiples de 400. Ce sont les années bissextiles.
    Une année est donc bissextile si elle est divisible par 4 et non-divisible par 100, ou si elle est divisible par 400.
    Ecrire un algorithme, et le programme C correspondant, permettant de savoir si une année est bissextile ou non. L’année sera entrée par l’utilisateur. Vérifier les résultats avec quelques exemples.
    Remarque : Le programme devra comporter une boucle pour gérer le cas des saisies d’un nombre négatif (en redemandant la saisie dans ce cas), et tourner indéfiniment (en demandant une nouvelle saisie après chaque affichage de résultat) tant qu’on ne le quitte pas par Ctrl-c (ou fermeture de la fenêtre console).


Exercice 3 : Jeu des allumettes

    Le jeu des allumettes est une déclinaison du jeu de Nim (ou jeu des bâtonnets dans l’émission Fort Boyard). Il se joue à deux. Il y a au départ N allumettes. Chacun à son tour, les 2 joueurs retirent entre n=1 et 3 allumettes. Celui qui retire la dernière allumette a perdu.
    Pour être sûr de gagner, il faut laisser à son adversaire un nombre d'allumettes correspondant à un multiple de 4, +1 (soit 5, 9, 13, 17, etc). En effet, supposons qu’il reste 5 allumettes, alors quel que soit le nombre pris par son adversaire, on est sûr de gagner au coup suivant. On peut remarquer que ces valeurs peuvent s’obtenir si l’on retire à chaque coup un nombre d’allumettes égal à : n = (allumettes-1) mod 4 (où allumettes est le nombre d’allumettes encore dans le jeu). 
    Rm : il faut gérer le cas n=0 (par exemple en prenant n=1).
    Si les deux adversaires connaissent et appliquent cette règle et que le nombre initial d’allumettes est un multiple de 4, celui qui commence est sûr de gagner.
    Exemples pour N=20, en considérant que l’adversaire ne connaît pas la règle et joue au hasard, et qu’on est toujours celui qui commence (rouge : adversaire ; bleu : soi-même) :
    1ère partie :   20 → (-3=)17 → (-1=)16 → (-3=)13 → (-2=)11 → (-2=)9 → (-3=)6 → (-1=)5 → gagné
    2e partie :     20 → (-3=)17 → (-3=)14 → (-1=)13 → (-1=)12 → (-3=)9 → (-2=)7 → (-2=)5 → gagné
        Ecrire un algorithme permettant de faire jouer alternativement l’ordinateur et le joueur.  L’ordinateur jouera de façon à gagner (cf règle ci-dessus), et le programme devra demander à l’utilisateur de saisir le nombre d’allumettes qu’il veut retirer. Le programme pourra être basé sur une boucle "tant que", à chaque itération de laquelle il faudra distinguer le cas Ordinateur ou Joueur.
        Ecrire le programme en langage C correspondant.


Exercice 4 : Diviseurs d’un nombre

	Ecrire un programme C pour déterminer et afficher tous les diviseurs d’un nombre positif (qu’on pourra fixer en "dur" dans le programme).
	Sachant qu’un nombre premier est un nombre qui ne peut être divisé que par 1 et par lui-même (par exemple 7), compléter ce programme pour déterminer (et afficher) si le nombre testé est premier ou non.
	Sachant qu’un nombre parfait est égal à la somme de ses diviseurs (stricts, c’est-à-dire à l’exclusion de lui-même), compléter ce programme pour déterminer (et afficher) si ce nombre est parfait ou non.
	Modifier ce programme pour déterminer quel est le 40000e nombre premier.


Exercice 5 (bonus) : Lecture à partir de la console et accumulation de valeurs

    Ecrire un programme permettant de saisir une valeur entière n positive, puis n valeurs positives également, au clavier (avec vérification, puis en redemandant à l’utilisateur de saisir le nombre tant que celui-ci est négatif), et calculant et affichant (à chaque saisie) : 
        les valeurs minimale et maximale de ces n valeurs
        leur moyenne
    et ceci sans utiliser un tableau.
    On utilisera la formule récursive de la moyenne :
    m_i=(〖(i-1).m〗_(i-1)+x_i)/i
    où xi est la ie valeur et mi la moyenne de i valeurs.
    Aurait-on pu utiliser une méthode plus simple (toujours sans utiliser de tableau) ?