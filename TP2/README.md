TP2 : Tableaux, fonctions


Exercice 1 : Fonctions d’affichage et de calcul de la moyenne des éléments d’un tableau

    On souhaite écrire un programme permettant d’afficher différentes informations sur le contenu d’un tableau d’entiers : - ses éléments eux-mêmes - leur moyenne - le min et le max 
        a)  Proposer un algorithme pour le calcul de la moyenne des éléments ainsi que les éléments min et max. 
        b)	Ecrire la fonction C correspondante
        c)	Ecrire un programme principal affichant les éléments du tableau et appliquant la fonction précédente à un petit tableau (d’une dizaine d’éléments) fixé dans le code-source. 


Exercice 2 : Tri par insertion

    On souhaite trier les éléments d’un tableau dans l’ordre croissant avec la méthode dite "par insertion".  
    Cette méthode consiste à prendre les éléments un par un, et, pour chacun d’entre eux, le comparer à tous ses voisins de gauche et décaler vers la droite tous ceux qui lui sont supérieurs. L’élément est alors inséré au dernier emplacement libéré.  
    Plus précisément, pour réaliser cette insertion, il suffit de comparer chaque élément du tableau (en commençant par le 2e, et jusqu’au dernier) à ses voisins de gauche, du plus proche au plus lointain, et tant qu’on trouve des éléments supérieurs, on décale ces derniers d’un rang vers la droite. Dès que l’on a trouvé un élément inférieur ou que l’on a atteint le début du tableau, on arrête les décalages et on insère l’élément à la dernière position libérée.  
    Exemple : tableau tab = {6, 0, 5, 3}  
            1e itération : traitement de 0 0 < 6 donc on décale le 6 stop → insertion du 0 à l’indice 0 → tab = {0, 6, 5, 3} 
            2e itération : traitement de 5 5 < 6 donc on décale le 6 5 > 0 → stop → insertion du 5 à l’indice 1 → tab = {0, 5, 6, 3} 
            3e itération : traitement de 3 3 < 6 donc on décale le 6 3 < 5 donc on décale le 5 3 > 0 → stop → insertion du 3 à l’indice 1 → tab = {0, 3, 5, 6}
        a)	Donner l’algorithme "insertion_element" réalisant cette opération d’insertion pour un seul élément, avec pour entrée /sortie le tableau à traiter, et pour autres entrées l’élément à insérer et son indice. Cet algorithme peut être basé sur une boucle "tant que", avec les conditions suivantes :  
            •	Il y a des voisins de gauche supérieurs à l’élément à insérer
            •	Le début du tableau n’a pas été atteint  
        Une fois ces décalages terminés, l’insertion peut alors être effectuée. 
        b)	Ecrire la fonction C correspondante. Elle devra avoir le prototype suivant :  
            void insertion_element(int tab[], int elem, int i_elem);  
            //tab : tableau, elem : élément à insérer, i_elem : indice de cet élément  
        c)	Ecrire un programme principal appliquant cette fonction aux éléments d’un tableau donné (par exemple celui utilisé ci-dessus) défini dans le code-source, et affichant les résultats. 



Exercice 3 : Détermination des racines d’un polynôme du 2e degré 

    a)	Ecrire une fonction dont le prototype est :
        float delta(float a, float b, float c); 
        Renvoyant le discriminant d’une équation du 2e degré à partir de ses coefficients a, b et c. 
    b)	Ecrire une fonction dont le prototype est :
        int nb_sol(float delta); 
        Renvoyant le nombre de racines (réelles) d’une équation du 2e degré à partir de son discriminant. 
    c)	Ecrire une fonction dont le prototype est :
        float f(float x, float a, float b, float c); 
        Retournant la valeur de l’image de l’abscisse x (a, b, c étant les coefficients du polynôme). 
    d)	Ecrire une fonction dont le prototype est :
        void f_tab(float *X, int nb_val, float a, float b, float c, float *Y); 
        Utilisant la fonction f(…) précédement définie, renvoyant le tableau de nb_val valeurs Y, images correspondantes aux nb_val valeurs d’un tableau X (avec a, b, c coefficients du polynôme). 
    e)	Pour tester ces fonctions, écrire un programme principal les appliquant au polynôme f(x) = ax²+ bx +c calculant ses éventuelles racines et les affichant.
        Pour les coefficients a, b, c, on pourra utiliser des valeurs fixées dans le programme ; elles devront être locales à la fonction main().
        On choisira des valeurs de coefficients correspondant à 1 ou 2 solutions, que l’on mettra en évidence en choisissant un tableau de valeurs adéquates à passer à la fonction f_tab(), dont on affichera le résultat.



Exercice 4 (Bonus) : Addition de 2 matrices

    Ecrire une fonction qui réalise l'addition de deux matrices A et B de même dimension N × M et retourne la matrice résultat C.
    La dimension ainsi que les éléments des matrices devront être rentrés à la main.