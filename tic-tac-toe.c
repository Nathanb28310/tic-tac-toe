#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pour ajouter les variables booléenes
#include <unistd.h>

int size = 3; // taille du plateau
int multi;

void free_tab(char **plateau) // libération de la mémoire allouée pour le plateau
{
    int i = 0;

    while (i < size)
    {
        free(plateau[i]);
        i = i + 1;
    }
    free(plateau);
}

char **creation_plateau(){ // création du plateau de jeu de taille size*size et le rempli d'espace vide
    char ** plateau = malloc(size * sizeof(char*));
    int i = 0;
    int j = 0; 
    while (i < size)
    {
        plateau[i] = malloc(size * sizeof(char));
        j = 0;
        while (j < size)
        {
            plateau[i][j] = ' ';
            j++;
        }
        i++;
    }
    return plateau;
}

void afficher_plateau(char **plateau){ // affiche le plateau
    printf("\n");
    int i = 0;
    while (i < size)
    {
        printf(" %c | %c | %c \n", plateau[i][0], plateau[i][1], plateau[i][2]);
        if (i < 2) {
            printf("-----------\n");
        }
        i++;
    }
    printf("\n");
}

bool verification_victoire(char** plateau, char symbole){ // vérifie les différents types de victoires
    int i = 0;
    bool victoire = false;
    while (i < size && victoire == false)
    {
        if ((plateau[i][0] == symbole && plateau[i][1] == symbole && plateau[i][2] == symbole) || (plateau[0][i] == symbole && plateau[1][i] == symbole && plateau[2][i] == symbole)) // vérifie les lignes et les colonnes
        {
            victoire = true;
        }
        i++;
    }
    if ((plateau[0][0] == symbole && plateau[1][1] == symbole && plateau[2][2] == symbole) || (plateau[0][2] == symbole && plateau[1][1] == symbole && plateau[2][0] == symbole)) // vérifie les diagonales
    {
            victoire = true;
    }
    return victoire;
}

bool verification_egalite(char** plateau){ // vérifie si il y a égalité, en regardant si il n'y a pas de case de vide
    int i = 0;
    int j = 0;
    bool egalite = true;
    while (i < size && egalite == true)
    {
        j = 0;
        while (j < size && egalite == true)
        {
            if (plateau[i][j] == ' ')
            {
                egalite = false;
            }
            j++;
        }
        i++;
    }   
    return egalite;   
}

int tour_joueur(char** plateau, char symbole) // gère le tour du joueur et vérifie les entrées du joueur pour éviter la triche
{
    int choix;
    bool verification = false;
    
    while (verification == false)
    {   
        printf("Choisissez où jouer (%c): \n", symbole);  
        int ret = scanf("%d", &choix);
        if (ret == EOF){
            free_tab(plateau);
            printf("\nFin du programme. Au revoir.\n");
            exit(0);
        }
        if (ret != 1) {  // vérifie si l'entrée n'est pas un entier
            printf("Erreur : Veuillez saisir un nombre entier\n");
            int c = getchar();
            while (c != '\n' && c != EOF) {
                c = getchar();
            };
            continue;
        }

        if (choix < 0 || choix > 8) { // vérification des limites du plateau (0 à 8)
            printf("Position invalide (doit être entre 0 et 8)\n");
            continue;
        }

        int ligne = choix / 3;
        int colonne = choix % 3;
        if (plateau[ligne][colonne] == 'X' || plateau[ligne][colonne] == 'O') // vérifie si la case est déjà prise
        {
            printf("Cette case est déjà occupée\n");
            continue;
        }
        plateau[ligne][colonne] = symbole; // place le symbole
        verification = true;
    }
    sleep(1); // pause d'une seconde pour l'affichage
    afficher_plateau(plateau);
    return 0;
    }


void tour_bot(char** plateau){ // gère le tour de l'ordinateur en plaçant son pion sur la première case vide trouvée
    int i = 0;
    int j = 0;
    bool choix = false;
    while (i < size && choix == false) {
        j = 0;
        while (j < size && choix == false) {
            if (plateau[i][j] == ' ') {
                plateau[i][j] = 'O';
                choix = true;
            }
            j++;
        }
        i++;
    }
    system("clear"); // permet de rafraichir le terminal
    afficher_plateau(plateau);
}

int mode_multi(char** plateau){ // demande si l'utilisateur veut jouer en multijoueur ou pas 
    bool verification = false;
    
    while (verification == false)
    {   
        printf("Voulez vous jouer en mode 2 joueur ? si oui mettez 2, sinon mettez 1 : \n");  
        int ret = scanf("%d", &multi);
        if (ret == EOF){
            free_tab(plateau);
            printf("\nFin du programme. Au revoir.\n");
            exit(0);
        }
        if (ret != 1) {  // vérifie si l'entrée n'est pas un entier
            printf("Erreur : Veuillez saisir un nombre entier\n");
            int c = getchar();
            while (c != '\n' && c != EOF) {
                c = getchar();
            };
            continue;
        }

        if (multi != 1 && multi != 2) {
            printf("Saisie invalide\n");
            continue;
        }
        verification = true;
    }
    return multi;
}