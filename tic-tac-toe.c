#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size = 3;

void free_tab(char **plateau)
{
    int i = 0;

    while (i < size)
    {
        free(plateau[i]);
        i = i + 1;
    }
    free(plateau);
}

char **creation_plateau(){
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

void afficher_plateau(char **plateau){
    system("clear");
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

bool verification_victoire(char** plateau, char symbole){
    int i = 0;
    bool victoire = false;
    while (i < size && victoire == false)
    {
        if (plateau[i][0] == symbole && plateau[i][1] == symbole && plateau[i][2] == symbole || plateau[0][i] == symbole && plateau[1][i] == symbole && plateau[2][i] == symbole)
        {
            victoire = true;
        }
        i++;
    }
    if (plateau[0][0] == symbole && plateau[1][1] == symbole && plateau[2][2] == symbole || plateau[0][2] == symbole && plateau[1][1] == symbole && plateau[2][0] == symbole)
    {
            victoire = true;
    }
    return victoire;
}

bool verification_egalite(char** plateau){
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

char **tour_joueur(char** plateau){
    int choix;

    printf("Choisissez où jouer :\n");
    scanf("%d", &choix);

    int ligne = (choix - 1) / 3;
    int colonne = (choix - 1) % 3;
    plateau[ligne][colonne] = 'x';
    afficher_plateau(plateau);

    return plateau;
}

char **tour_bot(char** plateau){
    int i = 0;
    int j = 0;
    bool choix = false;
    while (i < size && choix == false) {
        j = 0; // Réinitialisation indispensable pour chaque nouvelle ligne
        while (j < size && choix == false) {
            if (plateau[i][j] == ' ') {
                plateau[i][j] = 'o';
                choix = true;
            }
            j++;
        }
        i++;
    }
    afficher_plateau(plateau);
    return plateau;
}