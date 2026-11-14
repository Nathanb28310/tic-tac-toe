#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

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
            tour_joueur(plateau);
            victoire = verification_victoire(plateau, 'X');
            tour = 1;
        }
        else{
            tour_bot(plateau);
            victoire = verification_victoire(plateau, 'O');
            tour = 0;
        }
        egalite = verification_egalite(plateau);
        sleep(1);
    }
    system("clear");
    if (victoire == true && tour == 1)
    {
        printf("C'est gagné!\n");
    }
    else if (victoire == true && tour == 0)
    {
        printf("C'est perdu!\n");
    }
    else
    {
        printf("Match nul!\n");
    }
    free_tab(plateau);
    return 0;
}