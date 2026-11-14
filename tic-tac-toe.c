#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size = 3;

void free_tab(char **plateau)
{
    int i = 0;

    while (i < 3)
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
    while (choix == false)
    {
        while (i < size && choix == false)
        {
            j = 0;
            while (j < size && choix == false)
            {
                if (plateau[i][j] == ' ')
                {
                    plateau[i][j] = 'o';
                    choix = true;
                }
                j++;
            }
            i++;
        }
    }
    afficher_plateau(plateau);
    return plateau;
}