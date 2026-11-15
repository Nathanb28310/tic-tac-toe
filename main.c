#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(){
    char **plateau = creation_plateau();
    int tour = 0; // 0 pour le joueur ('X') et 1 pour l'ordinateur ('O')
    bool victoire = false;
    bool egalite = false;
    afficher_plateau(plateau);
    while (victoire == false && egalite == false) // tant qu'il n'y a ni victoire, ni égalité on continue la boucle de jeu
    {   
        if (tour == 0) // tour du joueur
        {
            tour_joueur(plateau);
            victoire = verification_victoire(plateau, 'X');
            tour = 1; // donne le tour à l'ordinateur
        }
        else{ // tour de l'ordinateur
            tour_bot(plateau);
            victoire = verification_victoire(plateau, 'O');
            tour = 0; // donne le tour au joueur
        }
        egalite = verification_egalite(plateau);
        sleep(1); // fais une pause de une seconde pour l'affichage
    }
    system("clear"); // permet de rafraichir le terminal
    if (victoire == true && tour == 1) // affichage des messages de fin en fonction du résultat
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
    free_tab(plateau); // libération de la mémoire allouée pour le plateau
    return 0;
}