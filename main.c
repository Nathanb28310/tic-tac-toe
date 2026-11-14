#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdbool.h>

int main(){
    char **plateau = creation_plateau();
    int tour = 0;
    bool victoire = false;
    bool egalite = false;
    afficher_plateau(plateau);
    while (victoire == false && egalite == false)
    {   
        if (tour == 0)
        {
            plateau = tour_joueur(plateau);
            victoire = verification_victoire(plateau, 'x');
            tour = 1;
        }
        else{
            plateau = tour_bot(plateau);
            victoire = verification_victoire(plateau, 'o');
            tour = 0;
        }
        egalite = verification_egalite(plateau);
    }
    if (victoire == true && tour == 1)
    {
        printf("C'est gagné\n");
    }
    else if (victoire == true && tour == 0)
    {
        printf("C'est perdu\n");
    }
    else
    {
        printf("Match nul\n");
    }
    free_tab(plateau);
    return 0;
}