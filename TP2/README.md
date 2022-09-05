TP2 : Tableaux, fonctions


Exercice 1 : Fonctions d’affichage et de calcul de la moyenne des éléments d’un tableau

    On souhaite écrire un programme permettant d’afficher différentes informations sur le contenu d’un tableau d’entiers :
        - ses éléments eux-mêmes
        - leur moyenne
        - le min et le max
    a) Proposer un algorithme pour le calcul de la moyenne des éléments ainsi que les éléments min et max.
    b) Ecrire la fonction C correspondante
    c) Ecrire un programme principal affichant les éléments du tableau et appliquant la fonction précédente à un petit tableau (d’une dizaine d’éléments) fixé dans le code-source.


Exercice 2 : Tri à bulle

    Le tri à bulle permet de trier les éléments d’un tableau dans l’ordre croissant. 
    Il consiste à parcourir tous les éléments de ce tableau, à comparer l’élément courant à l’élément suivant, et permuter ces 2 éléments s’ils ne sont pas dans l’ordre croissant. Le fait d’effectuer plusieurs fois ces opérations (parcours et permutations) permet de trier tout le tableau.
    Exemple pour le tableau dont le contenu est : "6 0 5 3"
    1er parcours :
        6 0 5 3 : On compare 6 et 0 -> on permute
        0 6 5 3 : On compare 6 et 5 -> on permute
        0 5 6 3 : On compare 6 et 3 -> on permute
    2e parcours :
        0 5 3 6 : On compare 0 et 5 -> on laisse
        0 5 3 6 : On compare 5 et 3 -> on permute
        0 3 5 6 : On compare 5 et 6 -> on laisse
    a) Ecrire un algorithme "permute_tab" permettant de permuter 2 éléments d’un tableau d’entiers. Les entrées de cet algorithme seront le tableau lui-même et les indices des 2 éléments à permuter.
    b) Ecrire la fonction C correspondante, dont le prototype doit être le suivant :
    void permute(int tab[], int i, int j); //i et j indices des éléments à permuter
    c) Ecrire l’algorithme effectuant ce tri (en utilisant l’algorithme précédemment écrit).
    d) Ecrire la fonction C correspondante
    e) Ecrire le programme principal et l’appliquer à un petit tableau (défini dans le programme).


Exercice 3 : Détermination des racines d’un polynôme du 2e degré

    a) Ecrire une fonction dont le prototype est 
    float delta(float a, float b, float c); 
    renvoyant le discriminant d’une équation du 2e degré à partir de ses coefficients a, b et c.
    b) Ecrire une fonction dont le prototype est 
    int nb_sol(float delta);
    renvoyant le nombre de racines (réelles) d’une équation du 2e degré à partir de son discriminant.
    c) Ecrire une fonction dont le prototype est
    float f(float x, float a, float b, float c);
    retournant la valeur de l’image de l’abscisse x (a, b, c étant les coefficient du polynôme).
    d) Ecrire une fonction dont le prototype est
    void f_tab(float *X, int nb_val, float a, float b, float c, float *Y);
    utilisant la fonction f(...) précédement définie, renvoyant le tableau de nb_val valeurs Y, images correspondantes aux nb_val valeurs d’un tableau X (avec a, b, c coefficients du polynôme).
    e) Pour tester ces fonctions, écrire un programme principal les appliquant au polynôme
    f(x) = ax2+ bx +c
    calculant ses éventuelles racines et les affichant.
    Pour les coefficients a, b, c, on pourra utiliser des valeurs fixées dans le programme ; elles devront être locales à la fonction main().
    On choisira des valeurs de coefficients correspondant à 1 ou 2 solutions, que l’on mettra en évidence en choisissant un tableau de valeurs adéquates à passer à la fonction f_tab(), dont on affichera le résultat.


Exercice 4 (Bonus) : Addition de 2 matrices

    Ecrire une fonction qui réalise l'addition de deux matrices A et B de même dimension N × M et retourne la matrice résultat C.
    La dimension ainsi que les éléments des matrices devront être rentrés à la main.